/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 03:06:46 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/09/02 03:11:09 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_monitoring(t_philo *philo)
{
	while (1)
	{
		if (ft_checkenougheat(philo) || ft_checkdeath(philo))
			return (1);
	}
	return (0);
}

int	ft_checkdeath(t_philo *philo)
{
	long	elapsed_time;
	int		i;

	i = 0;
	while (++i <= philo->param->nb_philos)
	{
		pthread_mutex_lock(&philo->param->common_access_mutex);
		elapsed_time = ft_elapsedtime(philo->last_eat,
				ft_gettime(philo->param->start));
		pthread_mutex_unlock(&philo->param->common_access_mutex);
		if (philo->status != EAT && elapsed_time >= philo->param->tm_die)
		{
			pthread_mutex_lock(&philo->param->common_access_mutex);
			philo->param->death = philo->id;
			pthread_mutex_unlock(&philo->param->common_access_mutex);
			ft_changestatus(philo, DIE);
			return (YES);
		}
		philo = philo->next;
	}
	return (NO);
}

int	ft_checkenougheat(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(&philo->param->common_access_mutex);
	res = (philo->param->need_to_eat_count == 0);
	pthread_mutex_unlock(&philo->param->common_access_mutex);
	return (res);
}

int	ft_game_is_on(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(&philo->param->common_access_mutex);
	if (philo->param->death == -1 && philo->param->need_to_eat_count != 0)
		res = 1;
	else
		res = 0;
	pthread_mutex_unlock(&philo->param->common_access_mutex);
	return (res);
}
