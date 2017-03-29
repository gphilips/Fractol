#include "fractol.h"

static int	ft_error(void)
{
	char *text;

	text = "usage : ./fractol <fractal's name>\nYou can use :\n- mandelbrot\n- julia\n- burninship";
	ft_putendl_fd(text, 2);
	return (-1);
}

int		main(int argc, char **argv)
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
	else
		return (ft_error());
	ft_create_win(e);
	return (0);
}
