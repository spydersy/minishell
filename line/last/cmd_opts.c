/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_opts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:02:35 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/30 09:19:18 by abelarif         ###   ########.fr       */
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
	printf("nb opts: %d\n", nb_opts);
	return (nb_opts);
}

int		get_end(char *s, int start)
{
	int		end;

	end = start;
	while (s[end] != '\0')
	{
		if (s[end] == ' ' || s[end] == '\t')
			break;
		else
			end++;
	}
	return (end);
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
	j = 0;
	opts = malloc(sizeof(char*) * ((nb_opts = count_opts(command)) + 1));
	if (opts == NULL)
		return (NULL);
	while (command[++i] != '\0')
	{
		if (command[i] == '\'' || command[i] == '\"')
			quote = manipquotes(quote, command[i]);
		if (command[i] == '-' && quote == 0
		&& (command[i - 1] == ' ' || command[i - 1]== '\t' || i == 0))
		{
			opts[j] = ft_substr(command, i, get_end(command, i) - i);
			j++;
		}
	}
	opts[j] = NULL;
	return ((char**)(opts));
}
