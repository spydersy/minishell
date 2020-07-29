/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:56:42 by eel-orch          #+#    #+#             */
/*   Updated: 2020/07/27 09:18:34 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		myft_strlen(const char *tab)
{
	int index;

	index = 0;
	if (tab == NULL)
		return (0);
	while (tab[index])
		index++;
	return (index);
}

char	*myft_strjoin(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*ptr;

	j = -1;
	i = 0;
	ptr = malloc((myft_strlen(s1) + myft_strlen(s2) + 1) * sizeof(char));
	if (ptr == NULL)
		return (0);
	if (s1 != NULL)
		while (s1[i] != '\0')
		{
			ptr[i] = s1[i];
			i++;
		}
	while (s2[++j] != '\0')
		ptr[i + j] = s2[j];
	ptr[i + j] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	int		j;
	int		index;
	char	*ptr;

	index = 0;
	j = -1;
	while (s[index])
		index++;
	index++;
	ptr = malloc(index * sizeof(char));
	if (ptr)
	{
		while (s[++j])
			ptr[j] = s[j];
		ptr[j] = '\0';
		return (ptr);
	}
	return (NULL);
}
