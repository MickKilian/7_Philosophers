/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:25:51 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/09/02 02:59:17 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_parsing(int argc, char **argv)
{
	int	res;

	res = 0;
	if (argc < 5 || argc > 6)
		res = ft_argerr();
	else
	{
		if (ft_atoi(argv[1]) < 1)
			res = printf("Error! %s\n", ERR_ARG1);
		if (ft_atoi(argv[2]) <= 0 || !ft_isvalidentry(argv[2]))
			res = printf("Error! %s\n", ERR_ARG2);
		if (ft_atoi(argv[3]) <= 0 || !ft_isvalidentry(argv[3]))
			res = printf("Error! %s\n", ERR_ARG3);
		if (ft_atoi(argv[4]) <= 0 || !ft_isvalidentry(argv[4]))
			res = printf("Error! %s\n", ERR_ARG4);
		if (argc == 6 && (ft_atoi(argv[5]) <= 0
				|| !ft_isvalidentry(argv[5])))
			res = printf("Error! %s\n", ERR_ARG5);
	}
	return (res);
}

int	ft_isvalidentry(char *src)
{
	char	*str;
	int		ret;

	str = ft_itoa(ft_atoi(src));
	ret = !ft_strncmp(str, src, ft_strlen(src));
	free(str);
	return (ret);
}

int	ft_argerr(void)
{
	printf("Error! Please specify exactly 4 [or 5] arguments\n");
	printf(" 1-> number_of_philosophers\n");
	printf(" 2-> time_to_die (ms)\n");
	printf(" 3-> time_to_eat (ms)\n");
	printf(" 4-> time_to_sleep (ms)\n");
	printf("[5-> number_of_times_each_philosopher_must_eat]\n");
	return (0);
}
