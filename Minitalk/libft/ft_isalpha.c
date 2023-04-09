/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:55:35 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 21:55:40 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int argument)
{
	if (argument >= 'a' & argument <= 'z')
		return (1);
	else if (argument >= 'A' & argument <= 'Z')
		return (1);
	else
		return (0);
}
