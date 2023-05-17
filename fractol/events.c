/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:09:21 by vbudilov          #+#    #+#             */
/*   Updated: 2023/05/15 20:07:00 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_f *f, double x, double y, double zoom)
{
	double	xx;
	double	yy;

	xx = ((x / WIDTH) * (f->end_x - f->start_x)) + f->start_x;
	yy = ((y / HIGHT) * (f->end_y - f->start_y)) + f->start_y;
	f->start_x = xx + ((f->start_x - xx) * zoom);
	f->start_y = yy + ((f->start_y - yy) * zoom);
	f->end_y = yy + ((f->end_y - yy) * zoom);
	f->end_x = xx + ((f->end_x - xx) * zoom);
	if (f->max <= 600)
		f->max += 2;
}

int	mouse_press(int button, int x, int y, t_f *f)
{
	if (button == 5 && f->stop == 1)
		zoom(f, (double)x, (double)y, 1.1);
	else if (button == 4 && f->stop == 1)
		zoom(f, (double)x, (double)y, 0.9);
	check_set(f);
	return (1);
}

int	press_exit(int keycode, void *f)
{
	(void)f;
	if (keycode == 53)
		exit(0);
	return (0);
}

int	ft_exit(int keycode, void *f)
{
	(void)f;
	(void)keycode;
	exit(0);
	return (0);
}

void	ft_mlx_hooks(t_f *f)
{
	mlx_put_image_to_window(f->ptr, f->win, f->image, 0, 0);
	mlx_hook(f->win, 4, 1, mouse_press, f);
	mlx_hook(f->win, 2, 1, press_exit, (void *)0);
	mlx_hook(f->win, 17, 1L << 2, ft_exit, (void *)0);
	mlx_loop(f->ptr);
}
