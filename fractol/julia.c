/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:00:28 by vbudilov          #+#    #+#             */
/*   Updated: 2023/05/09 16:00:30 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_f *f)
{
	mlx_clear_window(f->ptr, f->win);
	f->y_y = 0;
	while (f->y_y < WIDTH)
	{
		f->x_x = 0;
		while (f->x_x < HIGHT)
		{
			f->itier = 0;
			init_x_y(f);
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

void	init_julia(t_f *f, char *str, double x, double y)
{
	f->start_x = -2;
	f->end_x = 2;
	f->start_y = -2;
	f->end_y = 2;
	f->x_o = x;
	f->y_o = y;
	f->zoom = 0;
	f->stop = 0;
	f->max = 80;
	f->color = 30;
	f->name = str;
}
