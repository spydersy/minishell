/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:41:21 by abelarif          #+#    #+#             */
/*   Updated: 2021/03/01 16:17:31 by abelarif         ###   ########.fr       */
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
		if (first_time)
		{
			clear_window();
			first_time = 0;
		}
		prompt();
		/* ADD envp as parameter in extract_data() function */
		extract_command_line(read_line());
	}
	return (0);
}
