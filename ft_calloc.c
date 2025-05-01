/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:00:26 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/05/01 13:43:47 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	memsize;
	void	*ptr;
	// char	*char_ptr;

	if (nmemb == 0 || size == 0)
	{
		return (malloc(1));
	}
	memsize = nmemb * size;
	if (memsize / nmemb != size)
	{
		return (NULL);
	}
	ptr = malloc(memsize);
	if (!ptr)
	{
		return (NULL);
	}
	// char_ptr = (char *)ptr;
	ft_memset(ptr, 0, memsize);
	return (ptr);
}
