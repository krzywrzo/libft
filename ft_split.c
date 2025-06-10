<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:58:09 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/04/30 17:52:08 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int word_count(const char *str, char c);
static char *fill_word(const char *str, int start, int end);
static void *ft_free(char **strs, int count);
static void ft_initiate_vars(size_t *i, int *j, int *s_word);

char **ft_split(const char *s, char c)
{
    char **res;
    size_t i;
    int j;
    int s_word;
    
    ft_initiate_vars(&i, &j, &s_word);
    res = ft_calloc((word_count(s, c) + 1), sizeof(char *));
    if (!res)
        return (NULL);
    while (i <= ft_strlen(s))
    {
        if (s[i] != c && s_word < 0)
            s_word = i;
        else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
        {
            res[j] = fill_word(s, s_word, i);
            if (!(res[j]))
                return (ft_free(res, j));
            s_word = -1;
            j++;
        }
        i++;
    }
    return (res);
}

static void ft_initiate_vars(size_t *i, int *j, int *s_word)
{
    *i = 0;
    *j = 0;
    *s_word = -1;
}

static void *ft_free(char **strs, int count)
{
    int i;
    
    i = 0;
    while (i< count)
    {
        free(strs[i]);
        i++;
    }
    free(strs);
    return (NULL);
}

static char *fill_word(const char *str, int start, int end)
{
    char *word;
    int i;
    
    i = 0;
    word = malloc((end - start + 1) * sizeof(char));
    if (!word)
        return (NULL);
    while (start < end)
    {
        word[i] = str[start];
        i++;
        start++;
    }
    word[i] = 0;
    return (word);
}

static int word_count(const char *str, char c)
{
    int count;
    int x;
    
    count = 0;
    x = 0;
    while (*str)
    {
        if (*str != c && x == 0)
        {
            x = 1;
            count++;
        }
        else if (*str == c)
            x = 0;
        str++;
    }
    return (count);
=======
#include "libft.h"
static	int	count_arg(char const *s, char c)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			i++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (i);
}

static void	*ft_clean(char **list, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

static int	count_word(char *s, int c)
{
	int	i;

	i = 0;
	while (*s != c && *s)
	{
		i++;
		s++;
	}
	return (i);
>>>>>>> 7cc08fa (added ft_atol and slightly changed ft_split)
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**list;

	j = 0;
	i = count_arg((char *)s, c);
	list = malloc((i + 1) * sizeof(char *));
	if (list == NULL)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			list[j] = malloc(count_word((char *)s, c) + 1);
			if (list[j] == NULL)
				return (ft_clean(list, i));
			ft_strlcpy(list[j++], s, count_word((char *)s, c) + 1);
			s += count_word((char *)s, c) - 1;
		}
		s++;
	}
	list[j] = NULL;
	return (list);
}