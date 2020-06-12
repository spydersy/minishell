/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 20:17:44 by abelarif          #+#    #+#             */
/*   Updated: 2020/06/11 21:12:56 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	type_prompt()
{
	static int	first_time = 1;
	if (first_time)
	{
		const char	*CLEAR_SCREEN_ANSI = " \e[1;1H\e[2J";
		write (STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
		first_time = 0;
	}
	write (1, "MY_SHELL >>", 11);
}

void	read_command(char *cmd, char *par[])
{
	int		count;
	int		i;
	int		j;
	int		c;
	char	*array[100];
	char	*pch;
	char	line[1024];

	count = 0;
	i = 0;
	j = 0;
	for (;;)
	{
		c = fgetc(stdin);
		line[count++] = (char)c;
		if (c == '\n')
			break;
	}
	if (count == 1)
		return;
	pch = strtok(line, "\n");
	while (pch != NULL)
	{
		array[i++] = strdup(pch);
		pch = strtok(NULL, "\n");
	}
	strcpy(cmd, array[0]);
	for (int j = 0; j < i; j++)
		par[j] = array[j];
	par[i] = NULL;

}

int		main(int argc, char *argv[])
{
	char	command[100];
	char	cmd[100];
	char	*parameters[20];

	char *envp[] = {(char*) "PATH =/bin/", 0};
	while (1)
	{
		type_prompt();
		read_command(command, parameters);
		if (fork != 0)
			wait(NULL);
		else
		{
			strcpy(cmd, "/bin/");
			strcat(cmd, command);
			execve(cmd, parameters, envp);
		}
		if (strcmp(command, "exit") == 0)
			break;
	}
	return (0);
}