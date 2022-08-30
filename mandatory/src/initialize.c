/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 00:45:27 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/29 23:07:10 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_param(t_data *param, int argc, char **argv)
{
	param->nb_philos = ft_atoi(argv[1]);
	param->tm_die = ft_atoi(argv[2]) * 1000;
	param->tm_eat = ft_atoi(argv[3]) * 1000;
	param->tm_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		param->min_eats = ft_atoi(argv[5]);
	param->fork = (t_fork *)ft_mem_alloc(param->nb_philos * sizeof(t_fork));
	param->tempo = 10000;
	param->dead = -1;
	pthread_mutex_init(&param->wr_mutex, NULL);
	param->ft_action[0] = ft_takefork;
	param->ft_action[1] = ft_eat;
	param->ft_action[2] = ft_sleep;
	param->ft_action[3] = ft_think;
	//param->ft_action[4] = ft_die();
	param->txt_status[0] = " has taken a fork";
	param->txt_status[1] = " is eating";
	param->txt_status[2] = " is sleeping";
	param->txt_status[3] = " is thinking";
	param->txt_status[4] = " died";
	return (0);
}

t_philo	*ft_init_philo(t_data *param)
{
	int	i;
	t_philo *philo;

	i = 1;
	philo = ft_new_philo(NULL, param, 1);
	while (i++ < param->nb_philos)
	{
		philo->next = ft_new_philo(philo, param, i);
		philo = philo->next;
		//param->fork[i - 1].user = -1;
	}
	//philo = temp;
	philo = philo->next;
	return(philo);
}

t_philo	*ft_new_philo(t_philo *philo, t_data *param, int i)
{
	t_philo 	*new_philo;

	new_philo = (t_philo *)ft_mem_alloc(1 * sizeof(t_philo));
	new_philo->id = i;
	//pthread_mutex_init(&new_philo->mutex, NULL);
	//new_philo->fork = NO;
	new_philo->status = THINK;
	new_philo->param = param;
	new_philo->last_eat = 0;
	new_philo->nb_eats = 0;
	if (i == 1)
	{
		//new_philo->prev = new_philo;
		new_philo->next = new_philo;
	}
	else
	{
		//new_philo->prev = philo;
		new_philo->next = philo->next;
		//philo->next->prev=new_philo;
	}
	return (new_philo);
}
