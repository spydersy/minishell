/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ghem <ael-ghem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:07:06 by ael-ghem          #+#    #+#             */
/*   Updated: 2019/10/23 15:43:27 by ael-ghem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				l(char const *s, int i, char c)
{
	int count;

	count = 1;
	while (s[i])
	{
		if (s[i + 1] != c && s[i + 1] != '\0')
			count++;
		else
			break ;
		i++;
	}
	return (count);
}

static int				c_words(char const *str, char c)
{
	int words;
	int is_c;
	int i;

	i = 0;
	words = 0;
	is_c = 1;
	while (str[i])
	{
		if (str[i] == c)
			is_c = 1;
		else if (is_c == 1)
		{
			is_c = 0;
			words++;
		}
		i++;
	}
	return (words);
}

static int				d_job(char const *str, char c, int j, char **ret)
{
	int k;

	while (c_words(str, c))
	{
		while (*str == c || *str == '\0')
			str++;
		if (str)
		{
			k = 0;
			if (!(ret[j] = (char*)malloc(sizeof(char) * (l(str, 0, c) + 1))))
			{
				while (j)
					free(ret[--j]);
				return (-1);
			}
			while (*str != c && *str != '\0')
				ret[j][k++] = *str++;
			ret[j++][k] = '\0';
		}
	}
	return (j);
}

char					**ft_split(char const *str, char c)
{
	char	**ret;
	int		j;

	j = 0;
	ret = NULL;
	if (!str ||
	!(ret = (char**)malloc(sizeof(char*) * (c_words(str, c) + 1))))
		return (NULL);
	j = d_job(str, c, j, ret);
	if (j == -1)
	{
		free(ret);
		ret = NULL;
		return (NULL);
	}
	ret[j] = 0;
	return (ret);
}
