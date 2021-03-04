/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backslash_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:21:31 by abelarif          #+#    #+#             */
/*   Updated: 2021/03/04 07:20:15 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int         ft_char_match(char c, char *str)
{
	int     i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

int         count_bslash(char *line)
{
	char        *skip;
	t_quote     quote;
	int         nb;
	int         i;

	i = -1;
	nb = 0;
	skip = "abefnrtv'\"\\?";
	 
	quote = init_quote();
	while (line[++i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			quote = set_quote_value(line[i], quote);
		else if (line[i] == '\\' && ft_char_match(line[i + 1], skip))
			nb++;
	}
	return (nb);
}

int         *get_bslash_index(char *line, int nb)
{
	char        *skip;
	t_quote     quote;
	int         *index;
	int         i;
	int			c;

	c = -1;
	i = -1;
	skip = "abefnrtv'\"\\?";
	 
	quote = init_quote();
	if ((index = malloc(sizeof(int) * nb)) == NULL)
		ft_error(NULL);
	while (line[++i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			quote = set_quote_value(line[i], quote);
		else if (line[i] == '\\' && ft_char_match(line[i + 1], skip))
			index[++c] = i;
	}
	return (index);
}