/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 17:05:32 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/13 18:59:40 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_iter(int keycode, t_env *e)
{
	if (keycode == P && e->point.max_iter < 300)
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
	if (keycode == ENT && e->ftl == 0)
		ft_init_mandelbrot(e);
	else if (keycode == ENT && e->ftl == 1)
		ft_init_julia(e);
	else if (keycode == ENT && e->ftl == 2)
		ft_init_burningship(e);
	if (keycode == ENT && e->ftl == 3)
		ft_init_tricorn(e);
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

void	ft_change_julia(int keycode, t_env *e)
{
	if (e->ftl == 1)
	{
		if (keycode == ONE)
		{
			e->point.c_r = 0.285;
			e->point.c_i = 0.01;
		}
		if (keycode == TWO)
		{
			e->point.c_r = -1.147022285618;
			e->point.c_i = 0;
		}
		if (keycode == THREE)
		{
			e->point.c_r = -0.038088;
			e->point.c_i = 0.97;
		}
	}

}
