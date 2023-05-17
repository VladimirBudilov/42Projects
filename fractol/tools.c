/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:00:12 by vbudilov          #+#    #+#             */
/*   Updated: 2023/05/09 16:00:15 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_set(t_f *f)
{
	if (ft_str_cmp(f->name, "mandelbrot") == 0)
		mandelbrot(f);
	else if (ft_str_cmp(f->name, "julia") == 0)
		julia(f);
}

void	set_color(t_f *f, int color)
{
	f->index = (4 * WIDTH * f->y_y) + f->x_x * 4;
	f->ch[f->index] = (f->itier * f->color + 480 + 150) * color;
	f->ch[f->index + 1] = (f->itier * f->color + 32 + 24) * color;
	f->ch[f->index + 2] = (f->itier * f->color + 736 + 35) * color;
	f->ch[f->index + 3] = 0;
}

void	iter_loop(t_f *f)
{
	while (f->itier < f->max)
	{
		f->x_tmp = f->x * f->x - f->y * f->y;
		f->y_tmp = 2 * f->x * f->y;
		f->x = f->x_tmp + f->x_o;
		f->y = f->y_tmp + f->y_o;
		if (f->x * f->x + f->y * f->y > 4)
			break ;
		f->itier++;
	}
}

void	init(t_f *f, char *str)
{
	f->start_x = -2;
	f->end_x = 2;
	f->start_y = -2;
	f->end_y = 2;
	f->x_o = -0.4;
	f->y_o = 0.6;
	f->zoom = 0;
	f->stop = 0;
	f->max = 80;
	f->color = 30;
	f->name = str;
}

void	init_x_y(t_f *f)
{
	f->x = ((f->x_x / (double)WIDTH) * (f->end_x - f->start_x)) + f->start_x;
	f->y = ((f->y_y / (double)HIGHT) * (f->end_y - f->start_y)) + f->start_y;
}
