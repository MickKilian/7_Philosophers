/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 05:22:56 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/19 09:13:01 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"


void	ft_gettime(struct timeval *tick)
{
	gettimeofday(tick, NULL);
}

/*double	ft_tick_ms(struct timeval *tick)
{
	return (1e3 * tick->tv_sec + 1e-3*(tick->tv_usec));
}*/

double	ft_time_diff_ms(struct timeval *start, struct timeval *end)
{
	return (1e3 * (end->tv_sec - start->tv_sec) + 1e-3 * (end->tv_usec - start->tv_usec));
}
