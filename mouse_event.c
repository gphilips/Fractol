/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 17:06:12 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/13 17:30:13 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == CLICK_L || button == SCROLL_UP)
	{
		e->point.zoom_x *= 1.5;
		e->point.zoom_y *= 1.5;
		e->point.scale *= 1.5;
		e->point.x1 += x / 2 / e->point.zoom_x;
		e->point.y1 += y / 2 / e->point.zoom_y;
	}
	else if ((button == CLICK_R || button == SCROLL_DOWN)
			&& (e->point.zoom_x > 100 && e->point.zoom_y > 100))
	{
		e->point.zoom_x /= 1.5;
		e->point.zoom_y /= 1.5;
		e->point.scale /= 1.5;
		e->point.x1 -= x / 3 / e->point.zoom_x;
		e->point.y1 -= y / 3 / e->point.zoom_y;
	}
	ft_expose_hook(e);
	return (0);
}

int		ft_move_mouse(int x, int y, t_env *e)
{
	if (e->ftl == 1 && e->pause == 0)
	{
		e->point.c_r = (float)x / e->win_x;
		e->point.c_i = (float)y / e->win_y;
	}
	ft_expose_hook(e);
	return (0);
}
