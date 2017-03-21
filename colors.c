#include "fractol.h"

static void	ft_black(t_env *e)
{
	e->color.r = 0;
	e->color.g = 0;
	e->color.b = 0;
}

static void	ft_white(t_env *e)
{
	e->color.r = 255;
	e->color.g = 255;
	e->color.b = 255;
}

static void	ft_light_blue(t_env *e)
{
	e->color.r = 51;
	e->color.g = 153;
	e->color.b = 255;
}

static void	ft_light_red(t_env *e)
{
	e->color.r = 255;
	e->color.g = 25;
	e->color.b = 24;
}

void		ft_color(t_env *e, int x, int y, int i)
{
	if (i < e->point.max_iter)
		ft_black(e);
	else
	{
		if (e->color.id == 0)
			ft_light_blue(e);
		else if (e->color.id == 1)
			ft_light_red(e);
		else if (e->color.id == 2)
			ft_white(e);
	}
	ft_put_pixel(e, x, y);
}
