/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:12:39 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/08 20:24:30 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				list_reverselc(t_linecommand **g_linecommand)
{
	t_linecommand	*prev;
	t_linecommand	*current;
	t_linecommand	*next;

	prev = NULL;
	next = NULL;
	current = *g_linecommand;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*g_linecommand = prev;
}

int					manipquotes(int quote, int quote_type)
{
	if (quote_type == '\'' && !(quote % 2) && quote >= 10)
		return (quote);
	else if (quote_type == '\'' && quote % 2 == 1)
		return (quote - 1);
	if (quote_type == '\'' && !(quote % 2) && quote < 10)
		return (quote + 1);
	else if (quote_type == '\"' && (quote % 2))
		return (quote);
	else if (quote_type == '\"' && !(quote % 2) && quote < 10)
		return (quote + 10);
	else if (quote_type == '\"' && quote == 10)
		return (0);
	return (quote);
}

char				*get_split(char *line, int split_by, int quote)
{
	static int	i = -1;
	static int	old;

	old = i + 1;
	if (old > (int)ft_strlen(line))
	{
		old--;
		i = old - 1;
	}
	while (line[++i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			quote = manipquotes(quote, line[i]);
		if (line[i] == split_by && quote == 0)
			return (ft_substr(line, old, i - old));
	}
	if (!line[i] && i == old)
	{
		i = -1;
		return (NULL);
	}
	else if (!line[i] && i != old)
		return (ft_substr(line, old, i));
	return (NULL);
}

t_linecommand		*add_lc(char	*str, t_linecommand *lc)
{
	t_linecommand	*new_lc;
	
	new_lc = malloc(sizeof(t_linecommand));
	if (new_lc == NULL)
		return (NULL);
	new_lc->linecommand= str;
	new_lc->next = lc;
	return (new_lc);	
}

void				first_split()
{
	char	*split;

	while ((split = get_split(g_line, ';', 0)) != NULL)
		g_linecommand = add_lc(split, g_linecommand);
}
