/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:54:52 by vbudilov          #+#    #+#             */
/*   Updated: 2023/03/05 11:00:25 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "ft_printf.h"

int		ft_printf(const char *str, ...);
int		get_format(va_list ap, char format);

int		ft_strlen(char *str);
void	ft_put_char(int ch);
int		ft_print_char(int ch);
void	ft_put_str(char *str);
int		ft_print_str(char *input_str);

void	ft_put_pointer(unsigned long long ptr);
int		ft_print_pointer(unsigned long long ptr);

void	ft_put_nbr(int input_nbr);
int		ft_print_nbr(int input_nbr);
void	ft_put_uns_nbr(unsigned int nbr);
int		ft_print_uns_nbr(unsigned int input_nbr);

void	ft_put_hex(unsigned int nbr, char format);
int		ft_print_hex(unsigned int nbr, char format);

#endif
