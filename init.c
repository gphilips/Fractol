#include "fractol.h"

static void		ft_init_all(t_env *e)
{
	e->win_x = 1250;
	e->win_y = 700;
	e->mlx = NULL;
	e->win = NULL;
	e->img = NULL;
	e->color.r = 0;
	e->color.g = 0;
	e->color.b = 0;
}

void			ft_init_mandelbrot(t_env *e)
{
	if (!e->mlx && !e->win && !e->img)
		ft_init_all(e);
	e->ftl = 1;
	e->point.x1 = -2.1;
	e->point.x2 = 0.6;
	e->point.y1 = -1.2;
	e->point.y2 = 1.2;
	e->point.max_iter = 100;
	e->point.scale = 1;
	e->point.zoom_x = e->win_x / (e->point.x2 - e->point.x1);
	e->point.zoom_y = e->win_y / (e->point.y2 - e->point.y1);
}

void			ft_init_julia(t_env *e)
{
	if (!e->mlx && !e->win && !e->img)
		ft_init_all(e);
	e->ftl = 2;
	e->point.x1 = -1;
	e->point.x2 = 1;
	e->point.y1 = -1.2;
	e->point.y2 = 1.2;
	e->point.max_iter = 100;
	e->point.scale = 1;
	e->point.zoom_x = e->win_x / (e->point.x2 - e->point.x1);
	e->point.zoom_y = e->win_y / (e->point.y2 - e->point.y1);
}
