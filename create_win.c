/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:22:05 by gphilips          #+#    #+#             */
/*   Updated: 2017/06/02 15:01:54 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_instruction(t_env *e)
{
	char	*zoom;
	char	*iter;

	zoom = ft_itoa(e->point.zoom_x);
	iter = ft_itoa(e->point.max_iter);
	mlx_string_put(e->mlx, e->win, 10, 0, 0x00FFFFFF, CMD);
	mlx_string_put(e->mlx, e->win, 10, 10, 0x00FFFFFF, LINE);
	mlx_string_put(e->mlx, e->win, 10, 30, 0x00FFFFFF, ZOOM_IN);
	mlx_string_put(e->mlx, e->win, 10, 50, 0x00FFFFFF, ZOOM_OUT);
	mlx_string_put(e->mlx, e->win, 10, 70, 0x00FFFFFF, MOVE);
	mlx_string_put(e->mlx, e->win, 10, 90, 0x00FFFFFF, ITER);
	mlx_string_put(e->mlx, e->win, 10, 110, 0x00FFFFFF, COLOR);
	mlx_string_put(e->mlx, e->win, 10, 130, 0x00FFFFFF, FTL);
	mlx_string_put(e->mlx, e->win, 10, 150, 0x00FFFFFF, REINIT);
	if (e->ftl == 1)
	{
		mlx_string_put(e->mlx, e->win, 10, 170, 0x00FFFFFF, MAJ);
		mlx_string_put(e->mlx, e->win, 10, 190, 0x00FFFFFF, CHANGE);
	}
	mlx_string_put(e->mlx, e->win, 10, e->win_y - 50, 0x00FFFFFF, "Zoom:");
	mlx_string_put(e->mlx, e->win, 130, e->win_y - 50, 0x00FFFFFF, zoom);
	mlx_string_put(e->mlx, e->win, 10, e->win_y - 30, 0x00FFFFFF, "Iteration:");
	mlx_string_put(e->mlx, e->win, 130, e->win_y - 30, 0x00FFFFFF, iter);
	if (e->point.max_iter > 300)
		mlx_string_put(e->mlx, e->win, 170, e->win_y - 30, 0x00FFFFFF, "MAX!");
}

static int		ft_quit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	free(e);
	exit(0);
}

int				ft_expose_hook(t_env *e)
{
	e->img = mlx_new_image(e->mlx, e->win_x, e->win_y);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	ft_draw_fractal(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_instruction(e);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}

static int		ft_key_hook(int keycode, t_env *e)
{
	if (keycode == ESC)
		ft_quit(e);
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
		e->ftl = (e->ftl < 3) ? e->ftl + 1 : 0;
	if (keycode == SHIFT)
		e->pause = (e->pause == 0) ? 1 : 0;
	if (keycode == ONE || keycode == TWO || keycode == THREE)
		ft_change_julia(keycode, e);
	ft_expose_hook(e);
	return (0);
}

void			ft_create_win(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		ft_putendl_fd("Error minilibx init", 2);
	e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, "Fractol");
	mlx_hook(e->win, CLOSE, CLOSEMASK, ft_quit, e);
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, ft_key_hook, e);
	mlx_mouse_hook(e->win, ft_mouse_hook, e);
	mlx_hook(e->win, MOTIONNOTIFY, POINTERMOTIONMASK, ft_move_mouse, e);
	mlx_expose_hook(e->win, ft_expose_hook, e);
	mlx_loop(e->mlx);
}
