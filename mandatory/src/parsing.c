/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:25:51 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/28 19:11:22 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_parsing(int argc, char **argv)
{
	int	ret;

	ret = 0;
	if (argc < 5 || argc > 6)
	{
		ft_msgerr(ERR_ARGS);
		ft_msg(DEF_ARG1);
		ft_msg(DEF_ARG2);
		ft_msg(DEF_ARG3);
		ft_msg(DEF_ARG4);
		ret = ft_msg(DEF_ARG5);
	}
	else
	{
		if (ft_atoi(argv[1]) < 1)
			ret = ft_msgerr(ERR_ARG1);
		if (ft_atoi(argv[2]) <= 0)
			ret = ft_msgerr(ERR_ARG2);
		if (ft_atoi(argv[3]) <= 0)
			ret = ft_msgerr(ERR_ARG3);
		if (ft_atoi(argv[4]) <= 0)
			ret = ft_msgerr(ERR_ARG4);
		if (argc == 6 && ft_atoi(argv[5]) <= 0)
			ret = ft_msgerr(ERR_ARG5);
	}
	return (ret);
}
