/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:00:01 by vbudilov          #+#    #+#             */
/*   Updated: 2023/05/09 16:00:03 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 600
# define HIGHT 600

typedef struct set
{
	unsigned char	*ch;
	double			x;
	double			y;
	double			x_x;
	double			y_y;
	void			*ptr;
	void			*win;
	double			x_o;
	double			y_o;
	int				itier;
	double			x_tmp;
	double			y_tmp;
	void			*image;
	int				size_l;
	int				bpp;
	int				endian;
	int				index;
	char			*name;
	double			start_y;
	double			end_y;
	double			start_x;
	double			end_x;
	int				zoom;
	int				stop;
	int				max;
	int				color;

}					t_f;

typedef struct res
{
	double	result;
	int		sign;
	int		decimal;
	double	decimal_place;
}					t_res;

void				create_standard_fractal(t_f *f, char *name);
void				create_julia_with_params(t_f *f, char *name,
						char *x, char *y);
void				mandelbrot(t_f *f);
void				julia(t_f *f);
void				init_julia(t_f *f, char *str, double x, double y);
void				init(t_f *f, char *str);
int					mouse_press(int button, int x, int y, t_f *f);
void				iter_loop(t_f *f);
void				map_x_y(t_f *f);
double				ft_atof(char *str);
void				set_color(t_f *f, int color);
int					ft_str_cmp(char *s1, char *s2);
void				check_set(t_f *f);
void				zoom(t_f *f, double x, double y, double zoom);
void				ft_mlx_hooks(t_f *f);
void				init_x_y(t_f *f);
int					ft_str_isdigit(char *str);
int					ft_exit(int keycode, void *f);

#	endif
