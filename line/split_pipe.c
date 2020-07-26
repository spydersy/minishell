/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:20:12 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/23 12:19:19 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

void			list_reverse(t_splitpoint **split_point)
{
	t_splitpoint	*prev;
	t_splitpoint	*current;
	t_splitpoint	*next;

	prev = NULL;
	next = NULL;
	current = *split_point;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*split_point = prev;
}

int				get_nb_pipes(const char *long_command)
{
	int		i;
	int		quote;
	int		nb_pipes;

	nb_pipes = 0;
	quote = 0;
	i = -1;
	while (long_command[++i])
	{
		if (long_command[i] == '\'' || long_command[i] == '\"')
			quote = manipquotes(quote, long_command[i]);
		if (long_command[i] == '|' && quote == 0)
			nb_pipes++;
	}
	return (nb_pipes);
}

char			**get_pipe_split(char *command, int nb_pipes)
{
	int		i;
	char	**split_pipes;

	i = -1;
	split_pipes = malloc(sizeof(char*) * (nb_pipes + 2));
	while (++i <= nb_pipes)
		split_pipes[i] = get_split(command, '|');
	return (split_pipes);
}

void			ft_split_pipe(t_splitpoint *split_point)
{
	char	**split_pipe;

	// while (split_point != NULL)
	// {
		printf(">>%s<<\n", split_point->long_command);
		split_pipe = get_pipe_split(split_point->long_command,
		get_nb_pipes(split_point->long_command));
		// ft_manipulation(&split_pipe);
		// split_point = split_point->next;
	// }
	int	i = -1;
	while (split_pipe[++i])
		printf("%s\n", split_pipe[i]);
}