#include "fractol.h"

void	ft_iter(int keycode, t_env *e)
{
	if (keycode == P)
		e->point.max_iter *= 1.1;
	else if (keycode == L && e->point.max_iter > 100)
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
	{
		ft_init_mandelbrot(e);
		e->color.r = 10;
		e->color.g = 10;
		e->color.b = 10;
	}
	else if (keycode == ENT && e->ftl == 2)
	{
		ft_init_julia(e);
		e->color.r = 10;
		e->color.g = 10;
		e->color.b = 10;
	}
}

void	ft_change_rgb(int keycode, t_env *e)
{
	if (keycode == R)
		e->color.r += 10;
	else if (keycode == G)
		e->color.g += 10;
	else if (keycode == B)
		e->color.b += 10;
}
