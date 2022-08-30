/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:23:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/27 20:46:49 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	//ft_putnbr(ft_atoi(argv[1]));
	//return (0);
	if (ft_parsing(argc, argv))
		return (1);
	ft_philo(argc, argv);
	return (0);
}
