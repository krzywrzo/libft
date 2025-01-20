/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:48:38 by kwrzosek          #+#    #+#             */
/*   Updated: 2024/12/19 11:37:03 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystck, const char *ndl, size_t len)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	if (*ndl == '\0')
	{
		return ((char *)haystck);
	}
	while (haystck[i] && i < len)
	{
		j = 0;
		while (haystck[i + j] == ndl[j] && (i + j) < len)
		{
			j++;
			if (ndl[j] == '\0')
			{
				return ((char *)&haystck[i]);
			}
		}
		i++;
	}
	return (NULL);
}
