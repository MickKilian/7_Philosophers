/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 05:22:56 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/30 02:10:51 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


long long	ft_gettime(long long start)
{
	struct timeval	tick;

	gettimeofday(&tick, NULL);
	return (ft_elapsedtime(start, ft_us(tick)));
}

/*struct timeval	ft_time_diff(struct timeval *start, struct timeval *end)
{
	struct timeval	res;
	//printf("start : sec(%lu), usec(%lu)\n", start->tv_sec, start->tv_usec);
	//printf("end : sec(%lu), usec(%lu)\n", end->tv_sec, end->tv_usec);
	res.tv_sec = end->tv_sec - start->tv_sec;
	res.tv_usec = end->tv_usec - start->tv_usec;
	return (res);
}*/

long long	ft_us(struct timeval time)
{
	return (1e6 * time.tv_sec + time.tv_usec);
}

long long	ft_elapsedtime(double start, double tick)
{
	return (tick - start);
}

long long	ft_partms(long long time)
{
	return (time / 1000);
}

long long	ft_partus(long long time)
{
	return (time - (time / 1000) * 1000);
}

int	ft_myusleep(t_philo *philo, long long time)
{
	struct timeval	tick;
	long long	start_time;

	(void)philo;
	gettimeofday(&tick, NULL);
	start_time = ft_us(tick);
	while (ft_gettime(start_time) < time)
	{
		//if ((ft_dead_ex(philo) != -1 || ft_enough_eat_ex(philo)))
		//	return (1);
		usleep(USLEEP_INC);
	}
	return (0);
}
