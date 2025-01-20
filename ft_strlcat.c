/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:47:54 by kwrzosek          #+#    #+#             */
/*   Updated: 2024/12/19 11:42:30 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen((char *)src);
	if (dest_size == 0)
	{
		return (src_len);
	}
	dst_len = ft_strlen(dest);
	if (dest_size <= dst_len)
	{
		return (src_len + dest_size);
	}
	if (dst_len < dest_size - 1)
	{
		i = 0;
		while (dst_len + i < dest_size - 1 && src[i] != '\0')
		{
			dest[dst_len + i] = src[i];
			i++;
		}
		dest[dst_len + i] = '\0';
	}
	return (dst_len + src_len);
}
