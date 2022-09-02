/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 04:12:38 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/28 18:01:35 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_mem_alloc(int n)
{
	char	*str;

	str = malloc((n) * sizeof(char));
	if (!str)
		return (NULL);
	ft_bzero(str, n);
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(char *)s++ = '\0';
}

void	ft_free_philo(t_philo *philo)
{
	t_philo	*temp;
	int		nb;
	int		i;

	i = 0;
	nb = philo->param->nb_philos;
	while (++i < nb)
	{
		temp = philo->next;
		free(philo);
		philo = NULL;
		philo = temp;
	}
	free(philo);
}
