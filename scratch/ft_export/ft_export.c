/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 11:34:25 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/05 11:38:14 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		main(int argc, char*argv[], char *envp[])
{
	int		i;

	i = -1;
	if (argc && argv)
	{
		while (envp[++i])
		{
			if (ft_strncmp(envp[i], "_=", 2) != 0)
			{
				ft_putstr_fd("declare -x ", 1);
				ft_putendl_fd(envp[i], 1);
			}
		}
	}
	return (0);
}