/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:20:12 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/31 16:57:36 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_split_pipe(t_splitpoint *g_splitpt)
{
	int i = 0;
	while (g_splitpt != NULL)
	{
		ft_split_commands(g_splitpt->long_command);
		g_splitpt = g_splitpt->next;
	}
}






















































































// int				get_nb_pipes(const char *long_command)
// {
// 	int		i;
// 	int		quote;
// 	int		nb_pipes;

// 	nb_pipes = 0;
// 	quote = 0;
// 	i = -1;
// 	while (long_command[++i])
// 	{
// 		if (long_command[i] == '\'' || long_command[i] == '\"')
// 			quote = manipquotes(quote, long_command[i]);
// 		if (long_command[i] == '|' && quote == 0)
// 			nb_pipes++;
// 	}
// 	return (nb_pipes);
// }

// char			**get_pipe_split(char *command, int nb_pipes)
// {
// 	int		i;
// 	char	**split_pipes;

// 	i = -1;
// 	split_pipes = malloc(sizeof(char*) * (nb_pipes + 2));
// 	while (++i <= nb_pipes)
// 		split_pipes[i] = get_split(command, '|');
// 	return (split_pipes);
// }