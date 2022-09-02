/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 03:12:42 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/09/03 00:40:14 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	param;
	t_philo	*philo;

	if (ft_parsing(argc, argv))
		return (1);
	ft_bzero(&param, sizeof(t_data));
	ft_init_param(&param, argc, argv);
	philo = ft_init_philo(&param);
	if (param.nb_philos == 1)
		return (ft_case1philo(philo));
	//ft_startthreads(philo);
	ft_myusleep(philo, philo->tm_die / 2);
	ft_monitoring(philo);
	//ft_endthreads(philo);
	ft_free_philo(philo);
	sem_destroy(&param->forks_available)
	return (0);
}

int	ft_case1philo(t_philo *philo)
{
	struct timeval	tick;

	gettimeofday(&tick, NULL);
	philo->param->start = ft_us(tick);
	ft_changestatus(philo, FORK);
	ft_monitoring(philo);
	ft_free_philo(philo);
	return (0);
}
int	ft_makechildrenproc(t_philo *philo)
{
	int		i;

	i = 0;
	sem_wait(philo->common_access);
	while (i < philo->param->nb_philos)
	{
		philo->pid = fork();
		if (philo->pid == -1)
			return (1);
		if (philo->pid == 0)
		{
			ft_philolife(philo);
		}
		philo = philo->pid;
		i++;
	}
	i = 0;
	while (i < philo->param->nb_proc)
	{
		waitpid(philo->pid, NULL, 0);
		philo = philo->next;
		i++;
	}
	sem_post(philo->common_access);
	return (0);
}

void	ft_philolife(t_philo *philo_)
{
	sem_wait(philo->common_access);
	sem_post(philo->common_access);
	while (ft_game_is_on(philo))
	{
		if (ft_take2forks(philo) || ft_eat(philo)
			|| ft_sleep(philo) || ft_think(philo))
			break ;
	}
}

/*void	ft_startthreads(t_philo *philo)
{
	int				i;
	t_data			*param;
	struct timeval	tick;

	i = 0;
	pthread_mutex_lock(&philo->param->common_access_mutex);
	param = philo->param;
	while (i < param->nb_philos)
	{
		pthread_create(&philo->thread, NULL, ft_philolife, (void *)philo);
		philo = philo->next;
		i++;
	}
	gettimeofday(&tick, NULL);
	param->start = ft_us(tick);
	pthread_mutex_unlock(&philo->param->common_access_mutex);
}

void	ft_endthreads(t_philo *philo)
{
	int		i;
	t_data	*param;

	i = 0;
	param = philo->param;
	while (i < param->nb_philos)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
		i++;
	}
}*/
