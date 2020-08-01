/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 20:15:40 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/30 21:43:20 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <stdio.h>

int		main(int argc, char *argv[], char *envp[])
{
	char	*buf;

	buf = getcwd(buf, 800);
	if (buf == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	ft_putstr_fd(buf, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}

