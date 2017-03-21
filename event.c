#include "fractol.h"

void	ft_zoom(int keycode, t_env *e)
{
	if (keycode == PLUS)
		e->point.max_iter *= 1.1;
	else if (keycode == MIN)
		e->point.max_iter /= 1.1;
}

void	ft_move(int keycode, t_env *e)
{
	if (keycode == UP)
	{
		e->point.y1 += 0.1 / e->point.scale;
		e->point.y2 += 0.1 / e->point.scale; 
	}
	else if (keycode == DOWN)
	{
		e->point.y1 -= 0.1 / e->point.scale; 
		e->point.y2 -= 0.1 / e->point.scale; 
	}
	else if (keycode == LEFT)
	{
		e->point.x1 += 0.1 / e->point.scale; 
		e->point.x2 += 0.1 / e->point.scale;
	}
	else if (keycode == RIGHT)
	{
		e->point.x1 -= 0.1 / e->point.scale; 
		e->point.x2 -= 0.1 / e->point.scale;
	}
}

void	ft_reinit(int keycode, t_env *e)
{
	if (keycode == ENT && e->ftl == 1)
		ft_init_mandelbrot(e);
	else if (keycode == ENT && e->ftl == 2)
		ft_init_julia(e);
}

void	ft_change_color(int keycode, t_env *e)
{
	if (keycode == TAB && e->color.id != 2)
		e->color.id += 1;
	else
		e->color.id = 0;
}
