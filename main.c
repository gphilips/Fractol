/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:54:09 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/13 17:37:39 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_error(void)
{
	char	*usage;
	char	*list;

	usage = "usage : ./fractol <fractal's name>";
	list = "You can use :\n- mandelbrot\n- julia\n- burningship\n- tricorn\n";
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
	ft_putendl(ITER);
	ft_putendl(COLOR);
	ft_putendl(FTL);
	ft_putendl(REINIT);
	ft_putendl(MAJ);
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
	else if (ft_strcmp(argv[1], "tricorn") == 0)
		ft_init_tricorn(e);
	else
		return (ft_error());
	ft_info();
	ft_create_win(e);
	return (0);
}
