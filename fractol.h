#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# define ESC 53
# define P 35
# define L 37
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ENT 36
# define CLICK_L 1
# define CLICK_R 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define R 15
# define G 5
# define B 11
# define TAB 48
# define KEYPRESS 2
# define KEYPRESSMASK (1L<<2)
# define MOTIONNOTIFY 6
# define POINTERMOTIONMASK (1L<<6)


typedef struct	s_color
{
	int		r;
	int		g;
	int		b;

}				t_color;

typedef struct	s_point
{
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	int		max_iter;
	float	scale;
	float	zoom_x;
	float	zoom_y;
}				t_point;

typedef struct	s_env
{
	int		win_x;
	int		win_y;
	void	*mlx;
	void	*win;
	void	*img;
	int		bpp;
	int		sizeline;
	int		endian;
	char	*data;
	int		ftl;
	t_point	point;
	t_color	color;
}				t_env;

void	ft_init_mandelbrot(t_env *e);
void	ft_mandelbrot(t_env *e, t_point p, int x, int y);

void	ft_init_julia(t_env *e);
void	ft_julia(t_env *e, t_point p, int x, int y);

void	ft_init_burningship(t_env *e);
void	ft_burningship(t_env *e, t_point p, int x, int y);

void	ft_put_pixel(t_env *e, int x, int y, int color);
void	ft_change_color(t_env *e, int x, int y, int i);
void	ft_draw_fractal(t_env *e);

void	ft_iter(int keycode, t_env *e);
void	ft_move(int keycode, t_env *e);
void	ft_reinit(int keycode, t_env *e);
void	ft_change_rgb(int keycode, t_env *e);
void	ft_change_ftl(int keycode, t_env *e);
int		ft_move_mouse(int x, int y, t_env *e);
int		ft_mouse_hook(int button, int x, int y, t_env *e);
int		ft_expose_hook(t_env *e);
void	ft_create_win(t_env *e);
#endif
