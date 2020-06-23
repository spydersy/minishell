/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 20:57:01 by abelarif          #+#    #+#             */
/*   Updated: 2020/06/22 17:55:48 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

int		ft_d_quotes(int i, int quotes, int d_quotes)
{
	if (quotes)
		d_quotes = 0;
	else if (d_quotes)
		d_quotes = 0;
	else if (d_quotes == 0)
		d_quotes = i + 1;
	return (d_quotes);
}

int		ft_quotes(int i, int quotes, int d_quotes)
{
	if (d_quotes)
		quotes = 0;
	else if (quotes)
		quotes = 0;
	else if (quotes == 0)
		quotes = i + 1;
	return (quotes);
}

int		ft_sym(int c, char *str, int nb, int quotes, int d_quotes)
{
	int		i;

	i = 0;
	if (quotes || d_quotes)
		nb = nb;
	else if (quotes == 0 && d_quotes == 0)
	{
		nb++;
		if (c == 59 && g_line[i + 1] == c)
			printf("error\n");
		// if (id == 2)
		// 	return (1);
	}
	return (nb);
}

int		get_len(int index_line)
{
	int		len;
	int		d_quotes;
	int		quotes;

	len = 0;
	quotes = 0;
	d_quotes = 0;
	while (g_line[index_line])
	{
		if (g_line[index_line] == '\"' )
			d_quotes = ft_d_quotes(index_line, quotes, d_quotes);
		else if(g_line[index_line] == '\'')
			quotes = ft_quotes(index_line, quotes, d_quotes);
		else if (g_line[index_line] == ';')
		{
			if (ft_sym(2, index_line, 0, quotes, d_quotes))
				return (len);
		}
		index_line++;
		len++;	
	}
	return (len);
}
