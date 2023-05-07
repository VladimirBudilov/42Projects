/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:10:58 by vbudilov          #+#    #+#             */
/*   Updated: 2023/04/23 19:11:01 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"
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

void		check_ar(t_t *t)
{
	if (str_cmp(t->name, "mandelbrot") == 0)
		mandelbrot(t);
	else if (str_cmp(t->name, "julia") == 0)
		julia(t);
}

void	set_color(t_t *t, int color)
{
	t->index = (4 * WIDTH * t->y_y) + t->x_x * 4;
	t-h>c[t->index] = (t->itier * t->color + 580 + 150) * color;
	t->ch[t->index + 1] = (t->itier * t->color + 32 + 54) * color;
	t->ch[t->index + 2] = (t->itier * t->color + 736 + 35) * color;
	t->ch[t->index + 3] = 0;
}
void	itier_loop(t_t *t)
{
	while (t->itier < t->max)
	{
		t->xtmp = t->x * t->x - t->y * t->y;
		t->ytmp = 2 * t->x * t->y;
		t->x = t->xtmp + t->x_o;
		t->y = t->ytmp + t->y_o;
		if (t->x * t->x + t->y * t->y > 4)
			break ;
		t->itier++;
	}
}

void		zoom(t_t *t, double x, double y, double zoom)
{
	double	xx;
	double	yy;

	xx = ((x / WIDTH) * (t->end_x - t->start_x)) + t->start_x;
	yy = ((y / HIGHT) * (t->end_y - t->start_y)) + t->start_y;
	t->start_x = xx + ((t->start_x - xx) * zoom);
	t->start_y = yy + ((t->start_y - yy) * zoom);
	t->end_y = yy + ((t->end_y - yy) * zoom);
	t->end_x = xx + ((t->end_x - xx) * zoom);
	if (t->max <= 120)
		t->max += 2;
}

int		str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
