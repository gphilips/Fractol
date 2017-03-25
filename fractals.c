#include "fractol.h"

void	ft_mandelbrot(t_env *e, t_point p, int x, int y)
{
	int		i;
	float	tmp;
	
	p.c_r = x / p.zoom_x + p.x1;
	p.c_i = y / p.zoom_y + p.y1;
	p.z_r = 0;
	p.z_i = 0;
	i = -1;
	while ((p.z_r * p.z_r + p.z_i * p.z_i) < 4 && (++i < p.max_iter))
	{
		tmp = p.z_r;
		p.z_r = p.z_r * p.z_r - p.z_i * p.z_i + p.c_r;
		p.z_i = (2 * tmp * p.z_i) + p.c_i;
	}
	ft_change_color(e, x, y, i);
}

void	ft_julia(t_env *e, t_point p, int x, int y)
{
	int		i;
	float	tmp;
	
	p.c_r = -0.7726;
	p.c_i = 0.1242;
	p.z_r = x / p.zoom_x + p.x1;
	p.z_i = y / p.zoom_y + p.y1;
	i = -1;
	while ((p.z_r * p.z_r + p.z_i * p.z_i) < 4 && (++i < p.max_iter))
	{
		tmp = p.z_r;
		p.z_r = p.z_r * p.z_r - p.z_i * p.z_i + p.c_r;
		p.z_i = (2 * tmp * p.z_i) + p.c_i;
	}
	ft_change_color(e, x, y, i);
}
