/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:36:43 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/30 01:27:34 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_msg(char *str)
{
	ft_putstr(str);
	write (1, "\n", 1);
	return (1);
}

int	ft_msgerr(char *str)
{
	ft_putstr("Error! ");
	ft_putstr(str);
	write(1, "\n", 1);
	return (1);
}

void	ft_displaystate(t_philo *philo, long long time)
{
	pthread_mutex_lock(&philo->param->wr_mutex);
	ft_printtimems(time);
	write(1, " ", 1);
	ft_putnbr(philo->id);
	pthread_mutex_lock(&philo->status_ex);
	ft_putstr(philo->param->txt_status[philo->status]);
	pthread_mutex_unlock(&philo->status_ex);
	write(1, "\n", 1);
	pthread_mutex_unlock(&philo->param->wr_mutex);
}

void	ft_printtimems(long long time)
{
	ft_putnbr(ft_partms(time));
	write (1, " ", 1);
	//write (1, ".", 1);
	//ft_putnbr(ft_partus(time));
	write (1, "ms", 2);
}
