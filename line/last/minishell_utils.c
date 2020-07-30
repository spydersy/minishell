/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 19:36:29 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/29 20:09:15 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command		*add_commands(char *command, t_command *all_commands)
{
	t_command	*newcommand;

	newcommand = malloc(sizeof(t_command));
	newcommand->command = command;
	newcommand->next = all_commands;
	return (newcommand);
}

t_splitpoint	*add_split_point(char *str, t_splitpoint *split_point)
{
	t_splitpoint	*newsplit;

	newsplit = malloc(sizeof(t_splitpoint));
	newsplit->long_command = str;
	newsplit->next = split_point;
	return (newsplit);
}

void			list_reverse(t_splitpoint **split_point)
{
	t_splitpoint	*prev;
	t_splitpoint	*current;
	t_splitpoint	*next;

	prev = NULL;
	next = NULL;
	current = *split_point;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*split_point = prev;
}

int				manipquotes(int quote, int quote_type)
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

char			*get_split(char *line, int split_by)
{
	static int	i = -1;
	static int	old;
	int			quote;

	quote = 0;
	old = i + 1;
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
}