/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:55:23 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/30 11:53:20 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_n_redir(char *command)
{
	int		i;
	int		quote;
	int		nb_redir;

	nb_redir = 0;
	quote = 0;
	i = -1;
	while(command[++i] != '\0')
	{
		if (command[i] == '\'' || command[i] == '\"')
			quote = manipquotes(quote, command[i]);
		if (command[i] == '>' && command[i + 1] == '>' && quote == 0)
		{
			i++;
			nb_redir++;
		}
		else if ((command[i] == '<' || command[i] == '>') && quote == 0)
			nb_redir++;
	}
	return (nb_redir);
}

int		*get_redir(char *command, int n_redir)
{
	int		i;
	int		*redir;
	int		quote;
	int		j;
	// <   = 1;
	// >   = 2;
	// >>  = 3;

	i = -1;
	j = 0;
	quote = 0;
	redir = malloc(sizeof(int) * n_redir);
	while (command[++i] != '\0')
	{
		if (command[i] == '\'' || command[i] == '\"')
			quote = manipquotes(quote, command[i]);
		if (command[i] == '>' && command[i + 1] == '>' && quote == 0)
		{
			redir[j] = 3;
			j++;
			i++;
		}
		else if ((command[i] == '<' || command[i] == '>') && quote == 0)
		{
			redir[j] = ((command[i] == '<') ? (1) : (2));
			j++;
		}
	}
	return (redir);
}

char	*get_str(char *command, int start)
{
	while (command[++start])
	{
		if (!(command[start] == ' ' || command[start] == '\t'))
			break;
	}
	return (ft_substr(command, start, get_end(command, start) - start));
}

char	*manip_redir(char *command)
{
	static int		i = -1;
	static int		quote = 0;

	while (command[++i] != '\0')
	{
		if (command[i] == '\'' || command[i] == '\"')
			quote = manipquotes(quote, command[i]);
		if (command[i] == '>' && command[i + 1] == '>' && quote == 0)
		{
			i++;
			return (get_str(command, i));
		}
		else if ((command[i] == '<' || command[i] == '>') && quote == 0)
			return (get_str(command, i));
	}
	return (NULL);
}

char	**get_redir_to(char *command, int nb)
{
	int		j;
	char	**redir_to;

	j = 0;
	redir_to = malloc(sizeof(char*) * (nb + 1));
	while ((redir_to[j] = manip_redir(command)))
	{
		j++;
	}
	return (redir_to);
}
