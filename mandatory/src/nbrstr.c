/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 08:09:44 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/19 09:22:14 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

static	int	ft_power(int p)
{
	if (p == 0)
		return (1);
	return (10 * ft_power(p - 1));
}

static	int	ft_getsize(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		size++;
		n = -n;
	}
	else if (n == 0)
		return (1);
	while (n)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

/*char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		i;

	cpy = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(cpy + i) = *(s + i);
		i++;
	}
	*(cpy + i) = '\0';
	return (cpy);
}*/

char	*ft_nbrstr(double f)
{
	int		nb_carac;
	int		n;
	char	*str;

	n = (int)f;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb_carac = ft_getsize(n);
	str = ft_mem_alloc(nb_carac);
	while (nb_carac)
	{
		str[nb_carac] = (n / ft_power(nb_carac - 1)) + '0';
		n = n - (n / ft_power(nb_carac - 1) * ft_power(nb_carac - 1));
		nb_carac--;
	}
	return (str);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}
