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


int		destroy_exit(int keycode, t_t *t)
{
	mlx_destroy_image(t->ptr, t->image);
	mlx_destroy_window(t->ptr, t->win);
	free(t->ptr);
	return (0);
}

void		mlx_ho(t_t *t)
{
	mlx_put_image_to_window(t->ptr, t->win, t->image, 0, 0);
	mlx_hook(t->win, 4, 1, mouse_press, t);
	mlx_hook(t->win, 17, 0, destroy_exit, t);
	mlx_hook(t->win, 2, 1, key_press, t);
	mlx_loop(t->ptr);
}