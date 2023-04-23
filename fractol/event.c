/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:09:21 by vbudilov          #+#    #+#             */
/*   Updated: 2023/04/23 19:09:28 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_press(int button, int x, int y, t_t *t)
{
	if (button == 5 && t->stop == 1)
		zoom(t, (double)x, (double)y, 1.1);
	else if (button == 4 && t->stop == 1)
		zoom(t, (double)x, (double)y, 0.9);
	check_ar(t);
	return (1);
}

int			key_press(int keycode, t_t *t)
{
	if (keycode == 53)
	{
		destroy_exit(t);
		exit(0);
	}
	return (1);
}

void		init_x_y(t_t *t)
{
	t->x = ((t->x_x / (double)WIDTH) *
	(t->end_x - t->start_x)) + t->start_x;
	t->y = ((t->y_y / (double)HIGHT) *
	(t->end_y - t->start_y)) + t->start_y;
}

void		destroy_exit(t_t *t)
{
	mlx_destroy_image(t->ptr, t->image);
	mlx_destroy_window(t->ptr, t->win);
	free(t->ptr);
}
