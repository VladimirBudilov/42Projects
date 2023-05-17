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

int	main(int argc, char *argv[])
{
	t_f	f;

	if (argc == 2)
		create_standard_fractal(&f, argv[1]);
	else if (argc == 4 && ft_str_cmp(argv[1], "julia") == 0)
	{
		if (!ft_str_isdigit(argv[2]) || !ft_str_isdigit(argv[3]))
		{
			write(1, "Error", 5);
			return (0);
		}
		create_julia_with_params(&f, argv[1], argv[2], argv[3]);
	}
	else
	{
		write(1, "usage: ./fractol <name>", 23);
		write(1, "\tmandelbrot\tjulia\n", 19);
	}
	return (0);
}

void	create_standard_fractal(t_f *f, char *name)
{
	if (ft_str_cmp(name, "mandelbrot") == 0 || ft_str_cmp(name, "julia") == 0)
	{
		f->ptr = mlx_init();
		f->win = mlx_new_window(f->ptr, WIDTH, HIGHT, "Fractol");
		f->image = mlx_new_image(f->ptr, WIDTH, HIGHT);
		f->ch = (unsigned char *)mlx_get_data_addr(f->image,
				&f->bpp, &f->size_l, &f->endian);
		init(f, name);
	}
	check_set(f);
}

void	create_julia_with_params(t_f *f, char *name, char *x, char *y)
{
	f->ptr = mlx_init();
	f->win = mlx_new_window(f->ptr, WIDTH, HIGHT, "Fractol");
	f->image = mlx_new_image(f->ptr, WIDTH, HIGHT);
	f->ch = (unsigned char *)mlx_get_data_addr(f->image, &f->bpp,
			&f->size_l, &f->endian);
	init_julia(f, name, ft_atof(x), ft_atof(y));
	check_set(f);
}
