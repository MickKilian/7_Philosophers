/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:38:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/30 01:46:31 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo(int argc, char ** argv)
{
	t_data			param;
	t_philo			*philo;
	struct timeval	tick;

	ft_bzero(&param, sizeof(t_data));
	ft_init_param(&param, argc, argv);
	philo = ft_init_philo(&param);
	gettimeofday(&tick, NULL);
	param.start = ft_us(tick);
	ft_startthreads(philo);
	ft_monitoring(philo);
	ft_endthreads(philo);
	if (param.enough_eat)
		ft_msg(ENGH_EAT);
	if (param.dead != -1)
		ft_msg(PHI_DEAD);
	ft_free_philo(philo);
	free(param.fork);
	return (0);
}

void	*ft_philolife(void *philo_)
{
	t_philo	*philo;

	philo = (t_philo *)philo_;
	if (philo->id % 2 == 0)
		ft_myusleep(philo, EVENPHILO_OFFSET);
	while ((ft_dead_ex(philo) == -1) && !ft_enough_eat_ex(philo))
	{
		if (ft_take2forks(philo))
			break;
		ft_action(philo, EAT);
		ft_action(philo, SLEEP);
		ft_action(philo, THINK);
		//if (ft_take2forks(philo))
		//	break;
		//if (ft_action(philo, EAT))
		//	break;
		//if (ft_action(philo, SLEEP))
		//	break;
		//if (ft_action(philo, THINK))
		//	break;
	}
	return (NULL);
}

void	ft_startthreads(t_philo *philo)
{
	int		i;
	t_data	*param;

	i = 0;
	param = philo->param;
	while (i < param->nb_philos)
	{
		pthread_create(&philo->thread, NULL, ft_philolife, (void *)philo);
		philo = philo->next;
		i++;
	}
}

void	ft_endthreads(t_philo *philo)
{
	int		i;
	t_data	*param;

	i = 0;
	param = philo->param;
	while (i < param->nb_philos)
	{
		//printf("waiting philo-id : %d\n", philo->id);
		pthread_join(philo->thread, NULL);
		philo = philo->next;
		i++;
	}
}

int	ft_monitoring(t_philo *philo)
{
	while (1)
	{
		if (ft_checkenougheat(philo) || ft_checkdead(philo))
			return (1);
	}
	return (0);
}

int	ft_checkdead(t_philo *philo)
{
	long long	elapsed_time;
	int			i;

	i = 0;
	while (++i <= philo->param->nb_philos)
	{
		elapsed_time = ft_elapsedtime(ft_last_eat_ex(philo), ft_gettime(philo->param->start));
		if (ft_status_ex(philo) != EAT && elapsed_time >= philo->param->tm_die)
		{
			ft_dead_ex_ch(philo, philo->id);
			ft_changestate(philo, DIE);
			return (YES);
		}
		philo = philo->next;
	}
	return (NO);
}

int	ft_checkenougheat(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->param->min_eats)
	{
		while (++i <= philo->param->nb_philos)
		{
			if (ft_nb_eats_ex(philo) < philo->param->min_eats)
				return (ft_enough_eat_ex_ch(philo, NO));
			philo = philo->next;
		}
		return (ft_enough_eat_ex_ch(philo, YES));
	}
	return (ft_enough_eat_ex_ch(philo, NO));
}
