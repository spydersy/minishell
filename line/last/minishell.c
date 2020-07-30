/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 19:18:57 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/29 19:20:01 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				main(int argc, char *argv[], char *envp[])
{
	char		*line;

	if (get_next_line(0, &line) == -1)
		return (ft_error(-1));
	if (ft_line_manipulation(line) == -1)
		return (ft_error(-1));
	return (0);
}
