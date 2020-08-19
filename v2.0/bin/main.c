/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 14:26:19 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/13 14:57:03 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		main(int argc, char *argv[], char *envp[])
{
	char *args[2] = {"kh $SHELL iktf $ bfgn", NULL};
	execve("./ft_echo", args, envp);
	return (0);
}
