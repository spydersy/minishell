/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 20:18:40 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/30 09:53:22 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			manip_commands(t_command *all_commands)
{
	while (all_commands != NULL)
	{
		all_commands->cmd = get_cmd(all_commands->command);
		all_commands->bin = ((ft_strncmp(all_commands->cmd, "/bin/", 5) == 0)
		? (1) : (0));
		// all_commands->args = get_args(all_commands->command, all_commands);
		all_commands->opts = get_opts(all_commands->command);
		all_commands->n_redir = get_n_redir(all_commands->command);
		all_commands->redir = get_redir(all_commands->command);
		all_commands->redir_to = get_redir_to(all_commands->command);
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