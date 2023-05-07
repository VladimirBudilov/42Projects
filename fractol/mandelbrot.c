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

void	map(t_t *t)
{
	t->x = t->x_x / (WIDTH / (t->end_x - t->start_x)) + t->start_x;
	t->y = t->y_y / (HIGHT / (t->end_y - t->start_y)) + t->start_y;
	t->x_o = t->x;
	t->y_o = t->y;
}