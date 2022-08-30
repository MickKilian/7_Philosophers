/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:32:01 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/08/29 02:20:03 by mbourgeo         ###   ########.fr       */
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

/*char	*ft_strdup(const char *str)
{
	char	**temp;
	int		i;

	i = 0;
	temp = malloc((ft_strlen(str + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (str[i])
		temp[i] = str[i++];
	temp[i] = '\0';
	return (temp);
}*/

long long	ft_atoi(const char *nptr)
{
	long long	n;
	long long	sign;

	n = 0;
	sign = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || (*nptr == ' '))
		nptr++;
	if ((*nptr == '-') || (*nptr == '+'))
		sign = sign * (-2 * (*(nptr++) == '-') + 1);
	while (*nptr >= '0' && *nptr <= '9')
		n = n * 10 + *(nptr++) - '0';
	while (*nptr)
		nptr++;
	return (sign * n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	length;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (str - length);
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

char	*ft_itoa(int n)
{
	int		sign;
	int		nb_carac;
	char	*str;

	nb_carac = ft_getsize(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
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

char	*ft_strdup(const char *s)
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
}

void	ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	write(1, s, ft_strlen(s));
}

void	ft_putnbr(long long n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

void	ft_putnbrn(long long n, int len)
{
	char	c;

	if (n >= 10 || len > 1)
		ft_putnbrn(n / 10, len--);
	while (len-- > 1)
		write (1, "0", 1);
	c = n % 10 + '0';
	write (1, &c, 1);
}
