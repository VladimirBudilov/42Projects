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

void		mandelbrot(t_t *t)
{
	mlx_clear_window(t->ptr, t->win);
	t->y_y = 0;
	while (t->y_y < HIGHT)
	{
		t->x_x = 0;
		while (t->x_x < WIDTH)
		{
			t->itier = 0;
			map(t);
			itier_loop(t);
			if (t->itier == t->max)
				set_color(t, 0);
			else
				set_color(t, 1);
			t->x_x++;
		}
		t->y_y++;
	}
	t->stop = 1;
	mlx_ho(t);
}

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

void	map(t_t *t)
{
	t->x = t->x_x / (WIDTH / (t->end_x - t->start_x)) + t->start_x;
	t->y = t->y_y / (HIGHT / (t->end_y - t->start_y)) + t->start_y;
	t->x_o = t->x;
	t->y_o = t->y;
}
