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

int			press_exit(int keycode, void *f)
{
	(void)f;
	(void)keycode;
	exit(0);
	return (0);
}

void		mlx_ho(t_t *t)
{
	mlx_put_image_to_window(t->ptr, t->win, t->image, 0, 0);
	mlx_hook(t->win, 4, 1, mouse_press, t);
	mlx_hook(t->win, 2, 1, press_exit, (void*)0);
	mlx_hook(t->win, 17, 1L<<2, press_exit, (void*)0);
	mlx_loop(t->ptr);
}