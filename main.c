/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:41:21 by abelarif          #+#    #+#             */
/*   Updated: 2021/05/01 08:53:18 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

	/*
		
	*/

int		main(int argc, char *argv[], char *envp[])
{
	static int	first_time = 1;

	if (argv[1] != NULL || argc != 1)
	{
		ft_error("Arguments");
	}
	if (envp)
	{
		
	}
	while (1)
	{
			signal(SIGINT, prompt);
		if (first_time)
		{
			clear_window();
			first_time = 0;
		}
		prompt(0);
		/* ADD envp as parameter in extract_data() function */
		extract_command_line(read_line());
	}
	return (0);
}
