/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:13:54 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/29 21:13:58 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *string)
{
	size_t	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *string, int chr)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	if (chr == '\0')
		return ((char *)&string[ft_strlen(string)]);
	while (string[i] != '\0')
	{
		if (string[i] == (char) chr)
			return ((char *)&string[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *string, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!string)
	{
		string = (char *)malloc(1 * sizeof(char));
		string[0] = '\0';
	}
	if (!string || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(string) + ft_strlen(buff)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (string)
		while (string[++i] != '\0')
			str[i] = string[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(string) + ft_strlen(buff)] = '\0';
	free(string);
	return (str);
}

char	*ft_get_line(char *remainder)
{
	int		i;
	char	*str;

	i = 0;
	if (!remainder[i])
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		str[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
	{
		str[i] = remainder[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_remainder(char *remainder)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(remainder) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (remainder[i])
		str[j++] = remainder[i++];
	str[j] = '\0';
	free(remainder);
	return (str);
}
