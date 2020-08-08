/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 12:08:42 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/07 16:44:46 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_exit()
{
	char	**exit;
	int		nb;

	nb = 0;
	exit = mysplit(g_line, ' ', '\t');
	while (exit[nb])
		nb++;
	
	if (ft_strncmp("exit", exit[0], 4) == 0 && ft_strlen(exit[0]) == 4 && nb <=2)
	{
		// fre();
		return (1);
	}
	else if (ft_strncmp("exit", exit[0], 4) == 0 && ft_strlen(exit[0]) == 4 && nb > 2)
	{
		ft_putendl_fd("too many arguments", 1);
		return (0);
	}
	else
		return (0);
}

void	prompt_signal()
{
	ft_putstr_fd("\nminishell $ ", 1);
}

int		skip_bits(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == ' ' || line[i] == '\t'))
			return (i);
		i++;
	}
	return (i);
}

int		ignore_line()
{
	int i;

	i = -1;
	if (ft_strlen(g_line) == 0)
	{
		// free_line;
		return (1);
	}
	while (g_line[++i])
	{
		if (!(g_line[i] == ' ' || g_line[i] == '\t'))
			return (0);
	}
	// free_line;
	return (1);
}

void	init_var()
{
	g_linecommand = NULL;
	g_mycmd = ft_split("echo cd pwd export unset env exit < > >>", ' ');
	g_command = NULL;
}