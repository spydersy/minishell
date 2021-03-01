/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:54:31 by abelarif          #+#    #+#             */
/*   Updated: 2021/02/27 15:14:41 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int         skip_spaces(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' || line[i] != '\t')
			return (i);
		i++;
	}
	return (i);
}

int				count_words(char *line, t_backslash backslash)
{
	int     	i;
	int     	c;
	t_words		words;

	if (words.nb_words && backslash.backslash_index[0] && line)
	{
		
	}
	i = 0;
	c = 0;

	// while (line[i++])
	// {
	// }
	return (0);
}