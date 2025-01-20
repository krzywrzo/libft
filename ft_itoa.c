/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:43:53 by kwrzosek          #+#    #+#             */
/*   Updated: 2024/12/19 13:15:48 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_abs(long int nbr)
{
	if (nbr < 0)
	{
		return ((-1) * nbr);
	}
	else
	{
		return (nbr);
	}
}

static size_t	ft_int_len(int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		i++;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_sign(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n >= 0)
	{
		return (1);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	size_t	len;
	int		sign;
	char	*c;
	ssize_t	i;

	sign = ft_sign(n);
	len = ft_int_len(n);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
	{
		return (NULL);
	}
	if (sign == -1)
	{
		c[0] = '-';
	}
	i = len;
	c[len] = 0;
	while (--i >= (0 + (sign == -1)))
	{
		c[i] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
	}
	return (c);
}
