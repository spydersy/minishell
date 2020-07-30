/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_details.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:02:35 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/29 22:16:33 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

char	*get_cmd(char *command)
{
	int		i;
	int		start;

	i = 0;
	while (command[i])
	{
		if (command[i] == ' ' || command[i] == '\t')
			i++;
		else
			break;
	}
	start = i--;
	while (command[++i] != '\0')
	{
		if (command[i] == ' ' || command[i] == '\t')
			return (ft_substr(command, start, i - start));
	}
	return (ft_substr(command, start, i - start));
}

int		count_opts(char *command)
{
	int		quote;
	int		i;
	int		nb_opts;
	char	**opts;
	int		j;

	i = -1;
	quote = 0;
	nb_opts = 0;
	while (command[++i] != '\0')
	{
		if (command[i] == '\'' || command[i] == '\"')
			quote = manipquotes(quote, command[i]);
		if (command[i] == '-' && quote == 0
		&& (command[i - 1] == ' ' || command[i - 1] == '\t' || i == 0))
			nb_opts++;
	}
	return (nb_opts);
}

char	**get_opts(char	*command)
{
	char	**opts;
	int		i;
	int		j;
	int		nb_opts;
	int		quote;

	i = -1;
	quote = 0;
	j = -1;
	opts = malloc(sizeof(char*) * ((nb_opts = count_opts(command)) + 1));
	if (opts == NULL)
		return (NULL);
	while (++j < nb_opts)
	{
		while (command[++i] != '\0')
		{
			if (command[i] == '\'' || command[i] == '\"')
				quote = manipquotes(quote, command[i]);
			if (command[i] == '-' && quote == 0
			&& (command[i - 1] == ' ' || command[i - 1] == '\t' || i == 0))
				opts[j] = ft_substr(command, i, );
		}
	}
}

// int	main()
// {
// 	char	*str;

// 	str = "-hvk\"-vfds\"g -vfdsb -vfds -vfd";
// 	get_opts(str);
// 	return (0);
// }