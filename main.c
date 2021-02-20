/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:41:21 by abelarif          #+#    #+#             */
/*   Updated: 2021/02/19 16:32:05 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		extract_data(read_line());
	}
	return (0);
}