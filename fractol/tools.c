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
	t->ch[t->index] = (t->itier * t->color + 580 + 150) * color;
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

int		str_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

double ft_atof(char *str) {
    double result = 0.0;
    int sign = 1;
    int decimal = 0;
    double decimal_place = 1.0;
    
    if (*str == '-') {
        sign = -1;
        str++;
    }
    
    while (*str != '\0')
    {
        if (*str >= '0' && *str <= '9')
        {
            result = result * 10.0 + (*str - '0');
            if (decimal)
                decimal_place /= 10.0;
        }
        else if (*str == '.')
            decimal = 1;
        else
            break;
        str++;
    }
    
    result *= sign;
    if (decimal) {
        result *= decimal_place;
    }
    return result;
}

int	ft_str_isdigit(char *str)
{
    while(*str)
    {
        if ((*str >= '0' && *str <= '9') || *str == '.' || *str == '-')
		{
            str++;
            continue;
        }
    	return (0);
    }
	return 1;
}
