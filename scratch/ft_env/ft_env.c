/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 11:11:08 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/05 11:13:57 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		main(int argc, char *argv[], char *envp[])
{
	int		i;

	i = -1;
	if (argc && argv[0])
	{
		while (envp[++i])
			ft_putendl_fd(envp[i], 1);
	}	
	return (0);
}