/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 03:01:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/09/03 00:42:13 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_take2forks(t_philo *philo)
{

	sem_wait(&philo->param->forks_available);
	ft_changestatus(philo, FORK);
	if (!ft_game_is_on(philo))
		return (ft_letfork(philo));
	sem_wait(&philo->param->forks_available);
	ft_changestatus(philo, FORK);
	if (!ft_game_is_on(philo))
		return (ft_letfork(philo));
	return (0);
}

int	ft_letfork(t_philo *philo)
{
	sem_post(&philo->param->forks_available);
	sem_post(&philo->param->forks_available);
	return (1);
}

int	ft_eat(t_philo *philo)
{
	int	res;

	if (ft_changestatus(philo, EAT))
		return (1);
	sem_wait(&philo->param->common_access);
	philo->last_eat = ft_gettime(philo->param->start);
	sem_post(&philo->param->common_access);
	res = ft_myusleep(philo, philo->param->tm_eat);
	ft_letfork(philo);
	if (res || ft_update_eat_count(philo))
		return (1);
	return (0);
}

int	ft_update_eat_count(t_philo *philo)
{
	int	res;

	res = 0;
	philo->nb_eats++;
	if (philo->nb_eats == philo->min_eats)
	{
		sem_wait(&philo->param->common_access);
		if (--philo->param->need_to_eat_count == 0)
		{
			printf("%s\n", ENGH_EAT);
			res = 1;
		}
		sem_post(&philo->param->common_access);
	}
	return (res);
}
