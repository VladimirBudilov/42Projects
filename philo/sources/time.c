/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbudilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:50:25 by vbudilov          #+#    #+#             */
/*   Updated: 2023/06/02 15:50:27 by vbudilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long long int	current_time(long long int start_time)
{
	struct timeval	t1;
	long long int	milliseconds;

	gettimeofday(&t1, NULL);
	milliseconds = (t1.tv_sec * 1000LL + t1.tv_usec / 1000) - start_time;
	return (milliseconds);
}

long long int	get_time(void)
{
	struct timeval	t1;
	long long int	milliseconds;

	gettimeofday(&t1, NULL);
	milliseconds = (t1.tv_sec * 1000LL + t1.tv_usec / 1000);
	return (milliseconds);
}
