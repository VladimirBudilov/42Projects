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
	t->max = 80;
	t->color = 30;
	t->name = str;
}

void		check_ar(t_t *t)
{
	if (str_cmp(t->name, "mandelbrot") == 0)
		mandelbrot(t);
	else if (str_cmp(t->name, "julia") == 0)
		julia(t);
	else
	{
		write(1, "usage: ./fractol <name>", 23);
		write(1, "\tmandelbrot\tjulia\n", 19);
	}
}

int			main(int ac, char *av[])
{
	t_t		t;

	if (ac == 2)
	{
		if (str_cmp(av[1], "mandelbrot") == 0 || str_cmp(av[1], "julia") == 0)
		{
			t.ptr = mlx_init();
			t.win = mlx_new_window(t.ptr, WIDTH, HIGHT, "Fractol");
			t.image = mlx_new_image(t.ptr, WIDTH, HIGHT);
			t.ch = (unsigned char*)mlx_get_data_addr(t.image, &t.bpp
			, &t.size_l, &t.endian);
		}
		init(&t, av[1]);
		check_ar(&t);
	}
	else
	{
		write(1, "usage: ./fractol <name>", 23);
		write(1, "\tmandelbrot\tjulia\n", 19);
	}
	return (0);
}
