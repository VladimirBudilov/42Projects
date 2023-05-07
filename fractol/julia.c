/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:10:14 by vbudilov          #+#    #+#             */
/*   Updated: 2023/04/23 19:10:18 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia(t_t *t)
{
	mlx_clear_window(t->ptr, t->win);
	t->y_y = 0;
	while (t->y_y < WIDTH)
	{
		t->x_x = 0;
		while (t->x_x < HIGHT)
		{
			t->itier = 0;
			init_x_y(t);
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

void		init_x_y(t_t *t)
{
	t->x = ((t->x_x / (double)WIDTH) *
	(t->end_x - t->start_x)) + t->start_x;
	t->y = ((t->y_y / (double)HIGHT) *
	(t->end_y - t->start_y)) + t->start_y;
}


