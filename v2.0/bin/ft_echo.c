/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:17:31 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/19 17:25:36 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		get_len(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			return (i);
	}
	return (i);
}

int		ft_env(char *s, char *envp[])
{
	int		i;
	int		j;
	char	*env;

	i = get_len(s);
	j = -1;
	env = ft_substr(s, 0, i);
	if (i == 0)
	{
		ft_putchar_fd('$', 1);
		return (i);
	}
	while (envp[++j])
	{
		if (ft_strncmp(envp[j], env, ft_strlen(env)) == 0 && envp[j][i] == '=')
		{
			while (envp[j][++i])
				ft_putchar_fd(envp[i][j], 1);
		}
	}
	return (i + 1);
}

int		main(int argc, char *av[], char *ev[])
{
	int		n;
	int		i;
	int		j;

	n = ((ft_strlen(av[1]) == 2 && !ft_strncmp(av[1], "-n", 2)) ? (1) : (0));
	i = 0 + n;
	while (av[++i])
	{
		j = -1;
		if (i > 1)
			ft_putchar_fd(' ', 1);
		while (av[i][++j])
		{
			if (av[i][j] == '$')
				j += ft_env(av[i] + j + 1, ev);
			else
				ft_putchar_fd(av[i][j], 1);
		}
	}
	if (!n)
		ft_putchar_fd('\n', 1);
	return (0);
}
