/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 17:06:30 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/13 17:11:48 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (i != p.max_iter)
		ft_put_pixel(e, x, y, i * i);
}

void	ft_julia(t_env *e, t_point p, int x, int y)
{
	int		i;
	float	tmp;

	p.z_r = x / p.zoom_x + p.x1;
	p.z_i = y / p.zoom_y + p.y1;
	i = -1;
	while ((p.z_r * p.z_r + p.z_i * p.z_i) < 4 && (++i < p.max_iter))
	{
		tmp = p.z_r;
		p.z_r = p.z_r * p.z_r - p.z_i * p.z_i + p.c_r;
		p.z_i = (2 * tmp * p.z_i) + p.c_i;
	}
	if (i != p.max_iter)
		ft_put_pixel(e, x, y, i * i);
}

void	ft_burningship(t_env *e, t_point p, int x, int y)
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
		p.z_i = (2 * fabs(tmp * p.z_i)) + p.c_i;
	}
	if (i != p.max_iter)
		ft_put_pixel(e, x, y, i * i);
}

void	ft_tricorn(t_env *e, t_point p, int x, int y)
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
		p.z_i = (-2 * tmp * p.z_i) + p.c_i;
	}
	if (i != p.max_iter)
		ft_put_pixel(e, x, y, i * i);
}
