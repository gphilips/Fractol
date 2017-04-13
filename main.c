/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:54:09 by gphilips          #+#    #+#             */
/*   Updated: 2017/03/29 17:10:11 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_error(void)
{
	char	*usage;
	char	*list;

	usage = "usage : ./fractol <fractal's name>";
	list = "You can use :\n- mandelbrot\n- julia\n- burninship\n- buddhabrot";
	ft_putendl_fd(usage, 2);
	ft_putendl(list);
	return (-1);
}

static void		ft_info(void)
{
	ft_putendl(CMD);
	ft_putendl(LINE);
	ft_putendl(ZOOM_IN);
	ft_putendl(ZOOM_OUT);
	ft_putendl(MOVE);
	ft_putendl(ITER_P);
	ft_putendl(ITER_L);
	ft_putendl(COLOR);
	ft_putendl(FTL);
	ft_putendl(REINIT);
}

int				main(int argc, char **argv)
{
	t_env	*e;

	e = (t_env*)ft_memalloc(sizeof(t_env));
	if (argc != 2)
		return (ft_error());
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		ft_init_mandelbrot(e);
	else if (ft_strcmp(argv[1], "julia") == 0)
		ft_init_julia(e);
	else if (ft_strcmp(argv[1], "burningship") == 0)
		ft_init_burningship(e);
	else if (ft_strcmp(argv[1], "buddhabrot") == 0)
		ft_init_buddhabrot(e);
	else
		return (ft_error());
	ft_info();
	ft_create_win(e);
	return (0);
}
