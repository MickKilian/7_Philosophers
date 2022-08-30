/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:11:42 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/30 00:26:32 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_dead_ex(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(&philo->param->dead_ex);
	res = philo->param->dead;
	pthread_mutex_unlock(&philo->param->dead_ex);
	return (res);
}

int	ft_dead_ex_ch(t_philo *philo, int val)
{
	pthread_mutex_lock(&philo->param->dead_ex);
	philo->param->dead = val;
	pthread_mutex_unlock(&philo->param->dead_ex);
	return (val);
}

int	ft_enough_eat_ex(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(&philo->param->enough_eat_ex);
	res = philo->param->enough_eat;
	pthread_mutex_unlock(&philo->param->enough_eat_ex);
	return (res);
}

int	ft_enough_eat_ex_ch(t_philo *philo, int val)
{
	pthread_mutex_lock(&philo->param->enough_eat_ex);
	philo->param->enough_eat = val;
	pthread_mutex_unlock(&philo->param->enough_eat_ex);
	return (val);
}

int	ft_nb_eats_ex(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(&philo->nb_eats_ex);
	res = philo->nb_eats;
	pthread_mutex_unlock(&philo->nb_eats_ex);
	return (res);
}

int	ft_nb_eats_ex_ch(t_philo *philo, int val)
{
	pthread_mutex_lock(&philo->nb_eats_ex);
	philo->nb_eats = val;
	//printf("id : %d, val : %d\n", philo->id, val);
	pthread_mutex_unlock(&philo->nb_eats_ex);
	return (val);
}

int	ft_last_eat_ex(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(&philo->last_eat_ex);
	res = philo->last_eat;
	pthread_mutex_unlock(&philo->last_eat_ex);
	return (res);
}

int	ft_last_eat_ex_ch(t_philo *philo, int val)
{
	pthread_mutex_lock(&philo->last_eat_ex);
	philo->last_eat = val;
	pthread_mutex_unlock(&philo->last_eat_ex);
	return (val);
}

int	ft_status_ex(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(&philo->status_ex);
	res = philo->status;
	pthread_mutex_unlock(&philo->status_ex);
	return (res);
}

int	ft_status_ex_ch(t_philo *philo, int val)
{
	pthread_mutex_lock(&philo->status_ex);
	philo->status = val;
	pthread_mutex_unlock(&philo->status_ex);
	return (val);
}
