/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 19:18:57 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/07 11:20:55 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	type_prompt()
{
	static int		first_time = 1;
	if (first_time)
	{
		write(1, " \e[1;1H\e[2J", ft_strlen(" \e[1;1H\e[2J"));
		first_time = 0;
	}
	write(1, "MY_SHELL >>", 11);
}

void	prompt_signal()
{
	write(1, "\nMY_SHELL >>", 13);
}

int	skip_empty(char	*line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == ' ' || line[i] == '\t'))
			return (i);
	}
	return (i);
}

int		check_exit()
{
	int		nb;
	char	**exit;

	// exit = ft_split(g_line, ' ');

	if (ft_strncmp("exit", exit[0]))
		return (0);
	
}
int		main(int argc, char *rgv[], char *envp[])
{
	// siganl();
	signal(SIGINT, prompt_signal);
	while (1)
	{
		type_prompt();
		get_next_line(0, &g_line);
		if (check_exit() == 1)
		{
			ft_exit();
		}
	}
	return (0);
}
