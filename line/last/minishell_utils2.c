/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:05:00 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/31 17:30:00 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		skip_cmd(char *command)
{
	int		i;

	i = -1;
	while (command[++i])
	{
		if (!(command[i] == ' ' || command[i] == '\t'))
			break;
	}
	while (command[++i])
	{
		if (command[i] == ' ' || command[i] == '\t')
			break;
	}
	return (i);
}

void			list_reversecmd(t_command **g_command)
{
	t_command	*prev;
	t_command	*current;
	t_command	*next;

	prev = NULL;
	next = NULL;
	current = *g_command;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*g_command = prev;
}