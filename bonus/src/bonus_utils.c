/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:32:01 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/09/02 03:04:37 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (*str++)
		n++;
	return (n);
}

long	ft_atoi(const char *nptr)
{
	long	n;
	long	sign;

	n = 0;
	sign = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || (*nptr == ' '))
		nptr++;
	if ((*nptr == '-') || (*nptr == '+'))
		sign = sign * (-2 * (*(nptr++) == '-') + 1);
	while (*nptr >= '0' && *nptr <= '9')
		n = n * 10 + *(nptr++) - '0';
	if (*nptr)
		return (-1);
	return (sign * n);
}

static	int	ft_getsize(long n)
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

char	*ft_itoa(long n)
{
	int		sign;
	int		nb_carac;
	char	*str;

	nb_carac = ft_getsize(n);
	str = malloc((nb_carac + 1) * sizeof(char));
	if (!str)
		return (NULL);
	sign = (n < 0);
	n = n - 2 * n * (n < 0);
	if (sign == 1)
		str[0] = '-';
	str[nb_carac] = '\0';
	while (nb_carac - sign)
	{
		str[nb_carac - 1] = n % 10 + '0';
		n = n / 10;
		nb_carac--;
	}
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char	*t1;
	unsigned const char	*t2;

	t1 = (unsigned const char *)s1;
	t2 = (unsigned const char *)s2;
	while (n)
	{
		if (*t1 != *t2 || !*t1 || !*t2)
			return (*t1 - *t2);
		n--;
		t1++;
		t2++;
	}
	return (0);
}
