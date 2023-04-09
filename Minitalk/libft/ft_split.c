/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:27:16 by vbudilov          #+#    #+#             */
/*   Updated: 2023/01/23 22:27:19 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char separator)
{
	int	amount_of_words;
	int	trigger;

	amount_of_words = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != separator && trigger == 0)
		{
			trigger = 1;
			amount_of_words++;
		}
		else if (*str == separator)
			trigger = 0;
		str++;
	}
	return (amount_of_words);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		index;

	index = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[index++] = str[start++];
	word[index] = '\0';
	return (word);
}

char	**ft_split(char const *s1, char separator)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split_arr;

	split_arr = malloc((count_words(s1, separator) + 1)
			* sizeof(char *));
	if (!split_arr)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s1))
	{
		if (s1[i] != separator && index < 0)
			index = i;
		else if ((s1[i] == separator || i == ft_strlen(s1)) && index >= 0)
		{
			split_arr[j++] = word_dup(s1, index, i);
			index = -1;
		}
		i++;
	}
	split_arr[j] = 0;
	return (split_arr);
}
