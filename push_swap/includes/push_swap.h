/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:14:15 by vbudilov          #+#    #+#             */
/*   Updated: 2023/05/17 13:14:17 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdlib.h>
#include <limits.h>
#include "stdio.h"

int				is_valid_number(char *string);
int				ft_strisdigit(char *string);
int 			is_valid(char *string);
int				has_repeat(t_list **stack);
int				is_validate_atoi(const char *str);
void			add_to_list_from_str_with_space(t_list **head, char *string);
int				count_space(char *string);
int				has_space(char *string);
int 			str_is_correct(char *string);
int				ft_count_words(const char *str, char separator);




#endif //PUSH_SWAP_PUSH_SWAP_H
