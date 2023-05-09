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

int	main(int ac, char *av[])
{
	t_t	t;
	double	x;
	double	y;

	if (ac == 2)
	{
		if (str_cmp(av[1], "mandelbrot") == 0 || str_cmp(av[1], "julia") == 0)
		{
			t.ptr = mlx_init();
			t.win = mlx_new_window(t.ptr, WIDTH, HIGHT, "Fractol");
			t.image = mlx_new_image(t.ptr, WIDTH, HIGHT);
			t.ch = (unsigned char *)mlx_get_data_addr(t.image,
					&t.bpp, &t.size_l, &t.endian);
			init(&t, av[1]);
		}
		check_ar(&t);
	}
	else if (ac == 4 && str_cmp(av[1], "julia") == 0)
	{
		if (!ft_str_isdigit(av[2]) || !ft_str_isdigit(av[3]))
		{
			write(1, "Error", 5);
			return (0);
		}
		t.ptr = mlx_init();
		t.win = mlx_new_window(t.ptr, WIDTH, HIGHT, "Fractol");
		t.image = mlx_new_image(t.ptr, WIDTH, HIGHT);
		t.ch = (unsigned char *)mlx_get_data_addr(t.image, &t.bpp,
				&t.size_l, &t.endian);
		x = ft_atof(av[2]);
		y = ft_atof(av[3]);
		init_julia(&t, av[1], x, y);
		check_ar(&t);
	}
	else
	{
		write(1, "usage: ./fractol <name>", 23);
		write(1, "\tmandelbrot\tjulia\n", 19);
	}
	return (0);
}
