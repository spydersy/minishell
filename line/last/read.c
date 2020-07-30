/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:40:28 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/29 20:09:40 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			show_all(t_splitpoint *split_point)
{
	int	i;

	i = 0;
	while (split_point)
	{
		printf("%s\n", split_point->long_command);
		split_point = split_point->next;
		i++;
	}
	printf("%d\n", i);
}

int				ft_line_manipulation(char *line)
{
	t_splitpoint	*split_point;
	static int		nb;
	char			*long_command;

	split_point = NULL;
	while ((long_command = get_split(line, ';')) != NULL)
	{
		split_point = add_split_point(long_command, split_point);
		nb++;
	}
	list_reverse(&split_point);
	show_all(split_point);
	ft_split_pipe(split_point);
}