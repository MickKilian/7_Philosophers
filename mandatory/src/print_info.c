/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:36:43 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/19 09:17:45 by mbourgeo         ###   ########.fr       */

/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*int	ft_printstate(t_philo *philo)
{
	ft_msg(ft_strjoin(ft_itoa(philo->id), TXT_1));
	ft_msg(ft_strjoin(ft_itoa(philo->id), TXT_2));
	ft_msg(ft_strjoin(ft_itoa(philo->id), TXT_3));
	ft_msg(ft_strjoin(ft_itoa(philo->id), TXT_4));
	if (philo->status != DIE)
		ft_msg(ft_strjoin(ft_itoa(philo->id), TXT_5));
	return (0);
}*/

int	ft_msg(char *str)
{
	write (1, str, ft_strlen(str));
	write (1, "\n", 1);
	return (0);
}

void	ft_statechange(t_philo *philo, int status)
{
	struct timeval	tick;
	char			*temp;
	char			*temp_;

	ft_gettime(&tick);
	philo->status = status;
	temp = ft_strjoin(ft_nbrstr((ft_time_diff_ms(&philo->param.start, &tick))), " ");
	temp_ = ft_strjoin(temp, ft_nbrstr((philo->id)));
	free(temp);
	temp = ft_strjoin(temp_, " ");
	free(temp_);
	temp_ = ft_strjoin(temp, " ");
	free(temp);
	temp = ft_strjoin(temp_, philo->param.status[status]);
	free(temp_);
	ft_putstr_fd(temp, 1);
	free(temp);
}
