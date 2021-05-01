/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:21:39 by abelarif          #+#    #+#             */
/*   Updated: 2021/05/01 08:54:52 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_window(void)
{
	write(1, "\e[1;1H\e[2J", ft_strlen("\e[1;1H\e[2J"));
}

char	*read_line(void)
{
	char	*line;

	if (get_next_line(0, &line) < 0)
		ft_error("Get Next Line");
    return (line);
}

void	prompt(int sig)
{
	if (sig == 2)
		write(1, "\n", 1);
	write(1, KGRN, ft_strlen(KGRN));
	write(1, "MINISHELL > ", ft_strlen("MINISHELL > "));
	write(1, KWHT, ft_strlen(KWHT));
}