/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:20:12 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/26 19:08:58 by abelarif         ###   ########.fr       */
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

t_command		*add_commands(char *command, t_command *all_commands)
{
	t_command	*newcommand;

	newcommand = malloc(sizeof(t_command));
	newcommand->command = command;
	newcommand->next = all_commands;
	return (newcommand);
}

void			ft_split_commands(char *long_command)
{
	t_command	*all_commands;
	char		*command;

	all_commands = NULL;
	while ((command = get_split(long_command, '|')) != NULL)
	{
		all_commands = add_commands(command, all_commands);
		// all_commands->command = command;
		printf(">>%s<<\n", command);
	}
}

void			ft_split_pipe(t_splitpoint *split_point)
{
	int i = 0;
	while (split_point != NULL)
	{
		printf("voiiiiiiila %d\n", ++i);
		printf("voiiiiiiila check %s\n", split_point->long_command);
		ft_split_commands(split_point->long_command);
		split_point = split_point->next;
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