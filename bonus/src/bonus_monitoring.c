/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 03:06:46 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/09/03 00:49:00 by mbourgeo         ###   ########.fr       */
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
		sem_wait(&philo->param->common_access);
		elapsed_time = ft_elapsedtime(philo->last_eat,
				ft_gettime(philo->param->start));
		sem_post(&philo->param->common_access);
		if (philo->status != EAT && elapsed_time >= philo->param->tm_die)
		{
			sem_wait(&philo->param->common_access);
			philo->param->death = philo->id;
			sem_post(&philo->param->common_access);
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

	sem_wait(&philo->param->common_access);
	res = (philo->param->need_to_eat_count == 0);
	sem_post(&philo->param->common_access);
	return (res);
}

int	ft_game_is_on(t_philo *philo)
{
	int	res;

	sem_wait(&philo->param->common_access);
	if (philo->param->death == -1 && philo->param->need_to_eat_count != 0)
		res = 1;
	else
		res = 0;
	sem_post(&philo->param->common_access);
	return (res);
}
