/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:17:31 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/15 13:23:28 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		get_n(char *s)
{
	if (s == NULL)
		return (0);
	if (ft__strlen(s) == 2 && ft_strncmp(s, "-n", 2) == 0)
		return (1);
	return (0);
}

int		printf_env(char *s)
{
	int		i;
	char	*str;

	i = -1;
	while (s[++i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			break;
	}
	if (i == 0)
	{
		ft_puchar_fd('$', 1);
		return (0);
	}
	str = ft_substr(s, 0, i);
	printf("%s\n", str);
}

int		main(int argc, char *argv[], char *envp)
{
	int		n;
	int		i;
	int		j;

	n = get_n(argv[0]);
	i = -1 + n;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] != '$')
				ft_putchar_fd(argv[i][j], 1);
			else 
			{
				i += print_env(argv[i] + j);
			}
		}
	}
	return (0);
}

// int		get_n(char *s)
// {
// 	if (ft_strlen(s) != 2)
// 		return (0);
// 	if (ft_strncmp("-n", s, 2) != 0)
// 		return (0);
// 	return (1);
// }

// int		printf_env(char *s, char **env)
// {
// 	int		len;
// 	int		i;
// 	int		old_len;

// 	i = -1;
// 	len = ft_strlen(s);
// 	old_len = len;
// 	while (env[++i])
// 	{
// 		len = old_len;
// 		if (ft_strncmp(s, env[i], len) == 0 && env[i][len] == '=')
// 		{
// 			while (env[i][++len])
// 				ft_putchar_fd(env[i][len], 1);
// 			return (old_len + 1);
// 		}
// 	}
// 	return (old_len);
// }

// int		ft_env(char *s, char **env)
// {
// 	int		i;
// 	int		return_len;
// 	char	*var;

// 	i = -1;
// 	if (s[0] == ' ' || s[0] == '\t')
// 	{
// 		ft_putchar_fd('$', 1);
// 		return (0);
// 	}
// 	while (s[++i])
// 	{
// 		if ((s[i] == '\t' || s[i] == ' '))
// 			break;
// 	}
// 	if (i == 0)
// 	{
// 		ft_putchar_fd('$', 1);
// 		return (1);
// 	}
// 	var = ft_substr(s, 0, i);
// 	return_len = printf_env(var, env);
// 	//free();
// 	return (return_len - 1);
// }

// int		main(int c, char **v, char **envp)
// {
// 	int		n;
// 	int		i;
// 	int		j;

// 	int		argc = 1;
// 	char	*argv[] = {"kh", "$SHELL", "iktf", "$", "bfgn", "$kvhvgvu", NULL};
	
// 	if (!(c && v))
// 		return 0;
// 	if (argc == 0)
// 		ft_putchar_fd('\n', 1);
// 	else
// 	{
// 		n = get_n(argv[0]);
// 		i = -1 + n;
// 		while (argv[++i])
// 		{
// 			if (i > 0 + n)
// 				ft_putchar_fd(' ', 1);
// 			j = -1;
// 			while (argv[i][++j])
// 			{
// 				if (argv[i][j] != '$')
// 					ft_putchar_fd(argv[i][j], 1);
// 				else
// 					j += ft_env(argv[i] + j + 1, envp);
// 			}
// 		}
// 		if (n == 0)
// 			ft_putchar_fd('\n', 1);
// 	}
// 	return (0);
// }
