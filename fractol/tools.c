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

int		str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	set_color(t_t *t, int color)
{
	t->index = (4 * 1000 * t->y_y) + t->x_x * 4;
	t->ch[t->index] = (t->itier * t->color + 680 + 179) * color;
	t->ch[t->index + 1] = (t->itier * t->color + 42 + 84) * color;
	t->ch[t->index + 2] = (t->itier * t->color + 936 + 45) * color;
	t->ch[t->index + 3] = 0;
}

double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	map(t_t *t)
{
	t->x = t->x_x / (WIDTH / (t->end_x - t->start_x)) + t->start_x;
	t->y = t->y_y / (HIGHT / (t->end_y - t->start_y)) + t->start_y;
	t->x_o = t->x;
	t->y_o = t->y;
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
