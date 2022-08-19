/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:23:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/19 00:59:51 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		ft_msgerr(ERR_ARGS);
		ft_msgerr(DET_ARG1);
		ft_msgerr(DET_ARG2);
		ft_msgerr(DET_ARG3);
		ft_msgerr(DET_ARG4);
		return(ft_msgerr(DET_ARG5));
	}
	ft_philo(argc, argv);
	return (0);
}
