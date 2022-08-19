/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 00:45:27 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/19 08:04:50 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_param(t_data *param, struct timeval start, int argc, char **argv)
{
	param->nb_philos = ft_atoi(argv[1]);
	param->tm_die = ft_atoi(argv[2]) * 1000;
	param->tm_eat = ft_atoi(argv[3]) * 1000;
	param->tm_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		param->nb_eats = ft_atoi(argv[5]);
	param->start = start;
	param->status[1] = " has taken a fork";
	param->status[2] = " is eating";
	param->status[3] = " is sleeping";
	param->status[4] = " is thinking";
	param->status[5] = " died";
	return (0);
}

t_philo	*ft_init_philo(const t_data param)
{
	int	i;
	t_philo *philo;

	i = 1;
	philo = ft_new_philo(param, NULL, 1);
	while (i++ < param.nb_philos)
	{
		philo->next = ft_new_philo(param, philo, i);
		philo = philo->next;
	}
	//philo = temp;
	philo = philo->next;
	return(philo);
}

t_philo	*ft_new_philo(t_data param, t_philo *philo, int i)
{
	t_philo	*new_philo;

	new_philo = (t_philo *)ft_mem_alloc(1 * sizeof(t_philo));
	new_philo->id = i;
	pthread_mutex_init(&new_philo->mutex, NULL);
	new_philo->status = THINK;
	new_philo->st_eat = 0;
	new_philo->st_sleep = 0;
	new_philo->st_think = 0;
	new_philo->st_die = 0;
	if (i == 1)
	{
		new_philo->prev = new_philo;
		new_philo->next = new_philo;
	}
	else
	{
		new_philo->prev = philo;
		new_philo->next = philo->next;
		philo->next->prev=new_philo;
	}
	new_philo->param = param;
	return (new_philo);
}
