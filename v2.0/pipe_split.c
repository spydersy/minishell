/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:22:47 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/09 10:39:49 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*add_command(char *str, t_command *command)
{
	t_command		*new_command;
	// static int		id = 0;

	// if (command == NULL)
	// 	id = 0;
	new_command = malloc(sizeof(t_command));
	if (new_command == NULL)
		return (NULL);
	new_command->command = str;
	// new_command->id = ++id;
	new_command->next = command;
	return (new_command);
}

void		list_revrsecmd(t_command **g_command, int nb_cmd)
{
	t_command	*prev;
	t_command	*current;
	t_command	*next;

	prev = NULL;
	next = NULL;
	current = *g_command;	
	while (current != NULL)
	{
		current->nb_cmd = nb_cmd;
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*g_command = prev;
}

void	pipe_split(char *line)
{
	char		*command;
	static int	id = 0;

	command = NULL;
	if (command == NULL)
		id = 0;
	while ((command = get_split(line, '|', 0)) != NULL)
	{
		g_command = add_command(command, g_command);
		g_command->id = ++id;
		printf("id : (%d), nb_cmd : (%d), cmd : (%s)\n", g_command->id, g_command->nb_cmd, g_command->command);
		get_details(g_command);
	}
	list_revrsecmd(&g_command, g_command->id);
}