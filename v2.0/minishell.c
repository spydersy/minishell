/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 11:23:12 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/08 20:04:40 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	type_prompt(void)
{
	static int	first_time = 1;
	if (first_time == 1)
	{
		ft_putstr_fd(" \e[1;1H\e[2J", 1);
		first_time = 0;
	}
	ft_putstr_fd("minishell $ ", 1);
}

int		main(int argc, char *argv[], char *envp[])
{
	signal(SIGINT, prompt_signal);
	init_var();
	if (argc && argv && envp)
	{
		while (1)
		{
			type_prompt();
			get_next_line(0, &g_line);
			// if (check_exit() == 1)
			// {
			// 	ft_exit(); // SET LATER
			// }
			if (ignore_line() == 0)
			{
				// if (child != 0)
				// {
					ft_line();
				// }
			}
		}
	}
	return (0);
}
