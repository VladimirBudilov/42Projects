/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:53:23 by vbudilov          #+#    #+#             */
/*   Updated: 2023/02/19 11:53:27 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	get_format(va_list ap, char format)
{
	int	str_len;

	str_len = 0;
	if (format == 'c')
		str_len = ft_print_char(va_arg(ap, int));
	else if (format == 's')
		str_len = ft_print_str(va_arg(ap, char *));
	else if (format == 'p')
		str_len = ft_print_pointer(va_arg(ap, unsigned long long));
	else if (format == 'i' || format == 'd')
		str_len = ft_print_nbr(va_arg(ap, int));
	else if (format == 'u')
		str_len = ft_print_uns_nbr(va_arg(ap, unsigned int));
	else if (format == 'X' || format == 'x')
		str_len = ft_print_hex(va_arg(ap, unsigned int), format);
	else if (format == '%')
		str_len = ft_print_char('%');
	return (str_len);
}

int	ft_printf(const char *str, ...)
{
	int		index;
	int		str_len;
	va_list	ap;

	index = 0;
	str_len = 0;
	va_start(ap, str);
	while (str[index])
	{
		if (str[index] == '%')
		{
			index++;
			str_len += get_format(ap, str[index]);
		}
		else
			str_len += ft_print_char(str[index]);
		index++;
	}
	va_end(ap);
	return (str_len);
}
