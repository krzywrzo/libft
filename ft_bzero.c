/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:21:54 by kwrzosek          #+#    #+#             */
/*   Updated: 2024/12/19 11:40:33 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t size)
{
	size_t			i;
	unsigned char	*string;

	string = (unsigned char *)str;
	i = 0;
	while (i != size)
	{
		*string = '\0';
		string++;
		i++;
	}
}
