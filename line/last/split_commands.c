/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:18:40 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/31 17:32:43 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			manip_commands(t_command *commands)
{
	while (commands != NULL)
	{
		commands->cmd = get_cmd(commands->command);
		commands->bin = ((ft_strncmp(commands->cmd, "/bin/", 5) == 0)
		? (1) : (0));
		commands->opts = get_opts(commands->command);
		commands->n_redir = get_n_redir(commands->command);
		commands->redir = get_redir(commands->command, commands->n_redir);
		commands->redir_to = get_redir_to(commands->command,commands->n_redir);
		// redirect_to_cmd(commands);       choice binaries
		commands = commands->next;
	}
}

void			ft_split_commands(char *long_command)
{
	char		*command;

	g_command = NULL;
	while ((command = get_split(long_command, '|')) != NULL)
	{
		g_command = add_commands(command, g_command);
	}
	list_reversecmd(&g_command);
	manip_commands(g_command);
}