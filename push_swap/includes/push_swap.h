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
#include <stdio.h>

int				is_valid_number(char *string);
int				ft_strisdigit(char *string);
int 			is_valid(char *string);
int				has_repeat(t_list **stack);
int				is_validate_atoi(const char *str);
void			add_to_list_from_str_with_space(t_list **head, char *string);
int				has_space(char *string);
int 			str_is_correct(char *string);
int				ft_count_words(const char *str, char separator);

void            swap(t_list **stack);
void			swap_a(t_list **a);
void			swap_b(t_list **b);
void			rotate(t_list **stack);
void 			rotate_a(t_list **a);
void 			rotate_b(t_list **b);
void			push(t_list **source_stack, t_list **dest_stack);
void			push_a(t_list **a, t_list **b);
void			push_b(t_list **b, t_list **a);
void			reverse_rotate(t_list **stack);
void			reverse_rotate_a(t_list **a);
void			reverse_rotate_b(t_list **b);
void			ft_error(void);
void			add_index(t_list **stack);
int				list_is_sorted(t_list **stack);






#endif //PUSH_SWAP_PUSH_SWAP_H
