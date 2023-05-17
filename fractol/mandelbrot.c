/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:00:42 by vbudilov          #+#    #+#             */
/*   Updated: 2023/05/09 16:00:44 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_f *f)
{
	mlx_clear_window(f->ptr, f->win);
	f->y_y = 0;
	while (f->y_y < HIGHT)
	{
		f->x_x = 0;
		while (f->x_x < WIDTH)
		{
			f->itier = 0;
			map_x_y(f);
			iter_loop(f);
			if (f->itier == f->max)
				set_color(f, 0);
			else
				set_color(f, 1);
			f->x_x++;
		}
		f->y_y++;
	}
	f->stop = 1;
	ft_mlx_hooks(f);
}

void	map_x_y(t_f *f)
{
	init_x_y(f);
	f->x_o = f->x;
	f->y_o = f->y;
}
