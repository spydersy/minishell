/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 20:59:36 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/05 08:37:08 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	type_prompt()
{
	static int	first_time = 1;
	if (first_time == 1)
	{
		write(1, "", ft_strlen(""));
		first_time = 0;
	}
	write (1, "MINISHELL $ ", ft_strlne("MINISHELL $ "));
}

int		check_exit()
{
	int		i;

	i = -1;
	while (g_line[++i])
	{
		if (!(g_line[i] == ' ' || g_line[i] == '\t'))
			break;
	}
	if (ft_strncmp("exit", g_line + i, 4) != 0)
		return (0);
	i += 3;
	while (g_line[++i])
	{
		if (!(g_line[i] == ' ' || g_line[i] == '\t'))
			return (0);
	}
	return (1);
}

int		skip_line()
{
	int		i;

	i = -1;
	while (g_line[++i])
	{
		if (!(g_line[i] == ' ' || g_line[i] == '\t'))
			return (0);
	}
	return (1);
}

int		main()
{
	pid_t		child;

	while (1)
	{
		type_prompt();
		
		if (get_next_line(0, &g_line) == -1)
		{
			ft_error();
			return (-1);
		}
		if (check_exit() == 1)
			break;
		else if (skip_line() != 1)
		{
			child = fork();
		}
	}
	return (0);
}