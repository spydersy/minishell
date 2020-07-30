/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:18:40 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/30 10:42:30 by abelarif         ###   ########.fr       */
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
		// all_commands->args = get_args(all_commands->command, all_commands);
		commands->opts = get_opts(commands->command);
		commands->n_redir = get_n_redir(commands->command);
		commands->redir = get_redir(commands->command, commands->n_redir);
		commands->redir_to = get_redir_to(commands->command,commands->n_redir);
	}
}

void			ft_split_commands(char *long_command)
{
	t_command	*all_commands;
	char		*command;

	all_commands = NULL;
	while ((command = get_split(long_command, '|')) != NULL)
	{
		all_commands = add_commands(command, all_commands);
		// printf(">>%s<<\n", command);
	}
	list_reverse(all_commands);
	manip_commands(&all_commands);
}