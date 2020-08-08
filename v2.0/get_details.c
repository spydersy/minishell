/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_details.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 16:33:21 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/07 16:51:26 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cmd(char *command)
{
	int		i;
	int		start;

	i = 0;
	while (command[i])
	{
		if (command[i] == ' ' || command[i] == '\t')
			i++;
		else
			break;
	}
	start = i--;
	while (command[++i] != '\0')
	{
		if (command[i] == ' ' || command[i] == '\t')
			return (ft_substr(command, start, i - start));
	}
	return (ft_substr(command, start, i - start));
}

int		get_mycmd(char *cmd)
{
	int		i;

	i =-1;
	while (++i < 7)
	{
		if (ft_strlen(cmd) == ft_strlen(g_mycmd[i])
		&&  ft_strncmp(cmd, g_mycmd[i], ft_strlen(cmd) == 0))
			return (i);
	}
	return (-1);
}

int		get_bin(char *cmd)
{
	int		i;

	if (ft_strncmp(cmd, "/bin/", 5) == 0)
		return (1);
	return (0);
}

void	get_details(t_command *g_command)
{
	g_command->cmd = get_cmd(g_command->command);
	g_command->mycmd = get_mycmd(g_command->cmd);
	g_command->bin	= get_bin(g_command->cmd);
}