/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:17:34 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/10 10:53:31 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		main(int argc, char *argv[])
{
	int	return_chdir;

	if (argc > 2)
	{
		ft_putendl_fd("too many arguments", 2);
	}
	else if (argc == 0)
		return_chdir = chdir("/root");
	else
		chdir(argv[0]);
	printf("%d\n", return_chdir);
	if (return_chdir == -1)
	{
		ft_putendl_fd(strerror(errno), 2);
		return (-1);
	}
	return (0);
}
