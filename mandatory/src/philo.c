/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:38:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/19 09:09:18 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int ft_philo(int argc, char ** argv)
{
	t_data			param;
	t_philo			*philo;
	struct timeval	start;
	struct timeval	end;

	(void)end;
	ft_bzero(&param, sizeof(t_data));
	ft_gettime(&start);
	ft_init_param(&param, start, argc, argv);
	philo = ft_init_philo(param);
	//ft_printstate(philo);
	ft_roundcheck(&param, philo);
	ft_free_all(&philo);
	return (0);
}

void	*ft_trytoeat(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	while (1)
	{
		if (!pthread_mutex_lock(&philo->mutex) || !pthread_mutex_lock(&philo->next->mutex))
		{
			ft_statechange(philo, FORK);
			break;
			while (1)
			if (!pthread_mutex_lock(&philo->mutex) || !pthread_mutex_lock(&philo->next->mutex))
			{
				ft_statechange(philo, EAT);
				break;
			}
		}
	}
	printf(">%d starts eating\n", philo->id);
	usleep(philo->param.tm_eat);
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->next->mutex);
	ft_statechange(philo, SLEEP);
	usleep(philo->param.tm_sleep);
	ft_statechange(philo, THINK);
	philo->status = SLEEP;
	return (0);
}

void	ft_roundcheck(t_data *param, t_philo *philo)
{
	int		i;
	t_philo	*temp;

	temp = philo;
	i = 1;
	while (i <= param->nb_philos)
	{
		//printf("   checking Philo# %d\n", i);
		if (temp->status == THINK)
			//printf("prev/cur/next philo ids : %d, %d, %d\n", temp->prev->id, temp->id, temp->next->id);
			pthread_create(&temp->thread, NULL, ft_trytoeat, (void *)temp);
		temp = temp->next;
		i++;
	}
	temp = philo;
	i = 0;
	while (i < param->nb_philos)
	{
		pthread_join(temp->thread, NULL);
		temp = temp->next;
		i++;
	}
	printf("Finished...\n");
}
