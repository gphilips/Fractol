/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:21:37 by gphilips          #+#    #+#             */
/*   Updated: 2017/03/29 16:21:54 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_put_pixel(t_env *e, int x, int y, int iter)
{
	int		i;

	if ((x > 0 && x < e->win_x) && (y > 0 && y < e->win_y))
	{
		i = (y * e->sizeline) + (x * e->bpp / 8);
		e->data[i] = e->color.b + iter % 255;
		e->data[i + 1] = e->color.g + iter % 255;
		e->data[i + 2] = e->color.r + iter % 255;
	}
}

void		ft_change_color(t_env *e, int x, int y, int i)
{
	if (i < e->point.max_iter)
		ft_put_pixel(e, x, y, i);
	else
		ft_put_pixel(e, x, y, i);
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
			if (e->ftl == 0)
				ft_mandelbrot(e, e->point, x, y);
			if (e->ftl == 1)
				ft_julia(e, e->point, x, y);
			if (e->ftl == 2)
				ft_burningship(e, e->point, x, y);
		}
	}
}
