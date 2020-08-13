/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:17:31 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/12 16:05:40 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		check_nl(char *nl)
{
	if (ft_strlen(nl) != 2)
		return (0);
	else if (ft_strncmp(nl, "-n", 2) != 0)
		return (0);
	return (1);
}

void	put_env(char *str)
{
	// int		i;

	// i = -1;
	// while (str[++i])
	// {
	// 	if (!(str[i] == ' ' || str[i] == '\t'))
	// 	{
			
	// 	}
	// }
	printf("%s\n", envp[5]);
}

int		main(int argc, char *argv[], char *envp[])
{
	int		n;
	int		i;
	int		j;

	n = check_nl(argv[0]);
	i = -1 + n;
	j = -1;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] != '$')
				ft_putchar_fd(argv[i][j], 1);
			else
				put_env(argv[i] + j + 1);
		}
	}
	return (0);
}