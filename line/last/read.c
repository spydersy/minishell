/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:40:28 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/31 17:26:45 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			show_all(t_splitpoint *g_splitpt)
{
	int	i;

	i = 0;
	while (g_splitpt)
	{
		printf("%s\n", g_splitpt->long_command);
		g_splitpt = g_splitpt->next;
		i++;
	}
	printf("%d\n", i);
}

int				ft_line_manipulation(char *line)
{
	static int		nb;
	char			*long_command;

	g_splitpt = NULL;
	while ((long_command = get_split(line, ';')) != NULL)
	{
		g_splitpt = add_g_splitpt(long_command, g_splitpt);
		nb++;
	}
	list_reversept(&g_splitpt);
	show_all(g_splitpt);
	ft_split_pipe(g_splitpt);
}