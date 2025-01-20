/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:58:09 by kwrzosek          #+#    #+#             */
/*   Updated: 2024/12/19 13:12:06 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_split_size(char const *str, char c)
{
	int	count;
	int	key;

	count = 0;
	key = 0;
	while (*str != '\0')
	{
		if (*str != c)
			key = 1;
		else if (*str == c && key)
		{
			count++;
			key = 0;
		}
		str++;
	}
	if (key)
		count++;
	return (count);
}

static char	*ft_create_tokens(char *str, char c, int *begin_index)
{
	char	*token;
	int		last_index;
	int		i;

	while (str[*begin_index] == c && str[*begin_index] != '\0')
		(*begin_index)++;
	last_index = *begin_index;
	while (str[last_index] != c && str[last_index] != '\0')
		last_index++;
	if (last_index != *begin_index)
	{
		token = malloc(last_index - *begin_index + 1);
		if (token == NULL)
			return (NULL);
		i = 0;
		while (*begin_index < last_index && str[*begin_index] != c)
		{
			token[i] = str[*begin_index];
			i++;
			(*begin_index)++;
		}
		token[i] = '\0';
		return (token);
	}
	return (NULL);
}

static void	free_split(char **split)
{
	char	**splitt;

	splitt = split;
	while (*splitt != NULL)
	{
		free(*splitt);
		splitt++;
	}
	free(split);
}

char	**ft_split(char const *str, char c)
{
	unsigned int	split_size;
	char			**split_tokens;
	int				begin;
	int				i;
	char			*token;

	split_size = ft_split_size(str, c);
	split_tokens = (char **) malloc(sizeof(char *) * (split_size + 1));
	if (split_tokens == NULL || str == NULL)
		return (NULL);
	begin = 0;
	i = 0;
	while (split_size--)
	{
		token = ft_create_tokens((char *)str, c, &begin);
		if (token == NULL)
		{
			free_split(split_tokens);
			return (NULL);
		}
		split_tokens[i++] = token;
	}
	split_tokens[i] = NULL;
	return (split_tokens);
}
