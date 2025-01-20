/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:34:12 by kwrzosek          #+#    #+#             */
/*   Updated: 2024/12/19 11:55:45 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str2;

	str2 = (char *)str;
	start = 0;
	end = ft_strlen(str);
	i = 0;
	while (str[start] && ft_strchr(set, str[start]))
		start++;
	while (end > start && ft_strchr(set, str[end - 1]))
		end--;
	str2 = (char *)malloc(end - start + 1);
	if ((!str2) || (!str || !set))
		return (NULL);
	while (start < end)
	{
		str2[i] = str[start];
		i++;
		start++;
	}
	str2[i] = '\0';
	return (str2);
}
