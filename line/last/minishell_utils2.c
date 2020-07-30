/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 09:05:00 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/30 09:14:45 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		skip_cmd(char *command)
{
	int		i;

	i = -1;
	while (command[++i])
	{
		if (!(command[i] == ' ' || command[i] == '\t'))
			break;
	}
	while (command[++i])
	{
		if (command[i] == ' ' || command[i] == '\t')
			break;
	}
	return (i);
}
