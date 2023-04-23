/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:10:48 by vbudilov          #+#    #+#             */
/*   Updated: 2023/04/23 19:10:50 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"


void		init(t_t *t, char *str)
{
	t->start_x = -2;
	t->end_x = 2;
	t->start_y = -2;
	t->end_y = 2;
	t->x_o = -0.4;
	t->y_o = 0.6;
	t->zoom = 0;
	t->stop = 0;
	t->max = 40;
	t->color = 20;
	t->name = str;
}

void		check_ar(t_t *t)
{
	if (str_cmp(t->name, "Mandelbrot") == 0)
		mandelbrot(t);
	else if (str_cmp(t->name, "julia") == 0)
		julia(t);
	else
	{
		write(1, "usage: ./fractol <name>", 23);
		write(1, "\tMandelbrot\tBurningship\tJulia\n", 30);
	}
}

int			main(int ac, char *av[])
{
	t_t		t;

	if (ac == 2)
	{
		if (str_cmp(av[1], "Mandelbrot") == 0 || str_cmp(av[1], "julia") == 0)
		{
			t.ptr = mlx_init();
			t.win = mlx_new_window(t.ptr, 1000, 600, "Fractol");
			t.image = mlx_new_image(t.ptr, WIDTH + 400, HIGHT);
			t.ch = (unsigned char*)mlx_get_data_addr(t.image, &t.bpp
			, &t.size_l, &t.endian);
		}
		init(&t, av[1]);
		check_ar(&t);
	}
	else
	{
		write(1, "usage: ./fractol <name>", 23);
		write(1, "\tMandelbrot\tBurningship\tJulia\n", 30);
	}
	return (0);
}
