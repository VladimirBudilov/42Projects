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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>

int		is_valid_number(char *string);

int		ft_strisdigit(char *string);

int		is_valid(char *string, t_list **stack);

int		has_repeat(t_list **stack);

int		is_validate_atoi(const char *str);

void	add_to_list_from_str_with_space(t_list **head, char *string);

int		has_space(char *string);

int		str_is_correct(char *string, t_list **stack);

int		ft_count_words(const char *str, char separator);

void	swap(t_list **stack);

void	swap_a(t_list **a);

void	swap_b(t_list **b);

void	rotate(t_list **stack);

void	rotate_a(t_list **a);

void	rotate_b(t_list **b);

void	push(t_list **source_stack, t_list **dest_stack);

void	push_a(t_list **a, t_list **b);

void	push_b(t_list **b, t_list **a);

void	reverse_rotate(t_list **stack);

void	reverse_rotate_a(t_list **a);

void	reverse_rotate_b(t_list **b);

void	ft_error(t_list **stack_a);

void	add_index(t_list **stack);

int		list_is_sorted(t_list **stack);

void	push_smallest_node_to_stack_b_4(t_list **a, t_list **b);

void	push_smallest_node_to_stack_b_5(t_list **a, t_list **b);

t_list	*find_smallest_node(t_list **stack);

void	sort_5_nodes(t_list **a, t_list **b);

void	sort_4_nodes(t_list **a, t_list **b);

void	sort_3_nodes(t_list **stack);

void	sort_2_nodes(t_list **stack);

void	butterfly_sorting(t_list **stack_a, t_list **stack_b, int sqrt_len);

int		sqrt_len(t_list *stack);

int		ft_sqrt(int nb);

int		ft_find_max(t_list *stack);

void	push_all_to_stack_a(t_list **stack_a, t_list **stack_b);

void	create_list(t_list **stack, char *number);

void	do_sort(t_list **stack_a, t_list **stack_b);

void	free_stack(t_list **stack);

int		check_overflow(long long int res, long long int sign);

int		is_empty(t_list **current, t_list **head, int number);

void	free_array(char **array);

#endif
