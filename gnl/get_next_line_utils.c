/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:22:16 by abelarif          #+#    #+#             */
/*   Updated: 2021/02/19 16:05:37 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_nl(const char *rest)
{
	int i;

	i = 0;
	if (!rest)
		return (-1);
	while (rest[i])
	{
		if (rest[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*strjoin(char **rest, char *buf)
{
	int		lenrest;
	int		lenbuf;
	char	*p;
	int		i;
	int		j;

	lenbuf = ft_strlen(buf);
	lenrest = ft_strlen(*rest);
	if (!(p = malloc((lenrest + lenbuf + 1) * sizeof(char))))
		return (0);
	i = -1;
	while (++i < lenrest)
		p[i] = (*rest)[i];
	j = 0;
	while (i < (lenrest + lenbuf))
		p[i++] = buf[j++];
	p[i] = '\0';
	free_all(0, rest);
	return (p);
}

char	*r_r(char *rest, int index_nl)
{
	char	*r;
	int		i;
	int		len_rest;

	len_rest = (int)ft_strlen(rest);
	i = 0;
	if (!(r = malloc(sizeof(char) * (len_rest - index_nl))))
		return (0);
	while ((index_nl + 1) < len_rest)
	{
		r[i] = rest[index_nl + 1];
		i++;
		index_nl++;
	}
	r[i] = '\0';
	free(rest);
	return (r);
}

char	*r_l(char *rest, int index_nl)
{
	char	*l;
	int		i;

	i = 0;
	if (!(l = malloc(sizeof(char) * (index_nl + 1))))
		return (0);
	while (i < index_nl)
	{
		l[i] = rest[i];
		i++;
	}
	l[i] = '\0';
	return (l);
}
