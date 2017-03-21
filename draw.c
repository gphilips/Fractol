#include "fractol.h"

void		ft_put_pixel(t_env *e, int x, int y)
{
	int		i;
	
	if ((x > 0 && x < e->win_x) && (y > 0 && y < e->win_y))
	{
		i = (y * e->sizeline) + (x * e->bpp / 8);
		e->data[i] = e->color.b;
		e->data[i + 1] = e->color.g; 
		e->data[i + 2] = e->color.r;
	}
}

void		ft_draw_fractal(t_env *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->win_y)
	{
		x = -1;
		while (++x < e->win_x)
		{
			if (e->ftl == 1)
				ft_mandelbrot(e, e->point, x, y);
			if (e->ftl == 2)
				ft_julia(e, e->point, x, y);
		}
	}
}
