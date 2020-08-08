/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 12:58:17 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/07 15:12:52 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_line()
{
	first_split();
	list_reverselc(&g_linecommand);
	// while (g_linecommand)
	// {
	// 	printf(">>%s<<\n", g_linecommand->linecommand);
	// 	g_linecommand = g_linecommand->next;
	// }
	while (g_linecommand)
	{
		pipe_split(g_linecommand->linecommand);
		printf("***********\n");
		g_linecommand = g_linecommand->next;
	}
}