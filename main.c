#include "fractol.h"

static int	ft_error(int n)
{
	if (n == 1)
		ft_putendl_fd("usage: ./fractol <fractal name>", 2);
	return (-1);
}
int		main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error(1) == -1 ? -1 : 0);
	return (0);
}
