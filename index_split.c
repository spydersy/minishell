/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:03:02 by ael-ghem          #+#    #+#             */
/*   Updated: 2021/02/21 21:47:00 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**splitSep(char *line, int *sepIndex, int nbSep)
{
	int		i;
	char	**content;
	int		index;

	index = 0;
	i = -1;
	if ((content = malloc(sizeof(char*) * (nbSep + 2))) == NULL)
		return (NULL);
	while (++i < nbSep + 1)
	{
		if (i == nbSep)
		{
			index = ((i == 0) ? (sepIndex[nbSep - 1])
								: (sepIndex[nbSep - 1] + 1));
			content[i] = ft_substr(line, index, ft_strlen(line) - index);
			break;
		}
		content[i] = ft_substr(line, index, sepIndex[i] - index);
		if (content[i] == NULL)
			return (NULL);
		index = sepIndex[i] + 1;
	}
	content[nbSep + 1] = NULL;
	return (content);
}
