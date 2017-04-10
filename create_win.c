#include "fractol.h"

static void	ft_instruction(t_env *e)
{
	char	*line;
	char	*zoom_in;
	char	*zoom_out;
	char	*move;
	char	*iter_p;
	char	*iter_l;
	char	*color;
	char	*ftl;

	line = "___________________";
	zoom_in = "Left Click or Scroll Up : Zoom in\n";
	zoom_out = "Right Click or Scroll Down : Zoom out\n";
	move = "Arrow keys : Move the map\n";
	iter_p = "P : Increase the precision (change the foreground color)\n";
	iter_l = "L : Lower the precision (change the foreground color)\n";
	color = "R/G/B : Change the background color\n";
	ftl = "TAB : Change the fractal\n";
	mlx_string_put(e->mlx, e->win, 10, 0, 0x00FFFFFF, "COMMANDS");
	mlx_string_put(e->mlx, e->win, 10, 10, 0x00FFFFFF, line);
	mlx_string_put(e->mlx, e->win, 10, 30, 0x00FFFFFF, zoom_in);
	mlx_string_put(e->mlx, e->win, 10, 50, 0x00FFFFFF, zoom_out);
	mlx_string_put(e->mlx, e->win, 10, 70, 0x00FFFFFF, move);
	mlx_string_put(e->mlx, e->win, 10, 90, 0x00FFFFFF, iter_p);
	mlx_string_put(e->mlx, e->win, 10, 110, 0x00FFFFFF, iter_l);
	mlx_string_put(e->mlx, e->win, 10, 130, 0x00FFFFFF, color);
	mlx_string_put(e->mlx, e->win, 10, 150, 0x00FFFFFF, ftl);
}

int		ft_expose_hook(t_env *e)
{
	e->img = mlx_new_image(e->mlx, e->win_x, e->win_y);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	ft_draw_fractal(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_instruction(e);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}

static int	ft_key_hook(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode == P || keycode == L)
		ft_iter(keycode, e);
	if (keycode == UP || keycode == DOWN
		|| keycode == LEFT || keycode == RIGHT)
		ft_move(keycode, e);
	if (keycode == ENT)
		ft_reinit(keycode, e);
	if (keycode == R || keycode == G || keycode == B)
		ft_change_rgb(keycode, e);
	if (keycode == TAB)
		ft_change_ftl(keycode, e);
	ft_expose_hook(e);
	return (0);
}

void		ft_create_win(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		ft_putendl_fd("Error minilibx init", 2);
	e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, "Fractol");
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, ft_key_hook, e);
	mlx_mouse_hook(e->win, ft_mouse_hook, e);
	mlx_hook(e->win, MOTIONNOTIFY, POINTERMOTIONMASK, ft_move_mouse, e);
	mlx_expose_hook(e->win, ft_expose_hook, e);
	mlx_loop(e->mlx);
}
