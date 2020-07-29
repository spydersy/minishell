/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:58:57 by eel-orch          #+#    #+#             */
/*   Updated: 2020/07/27 09:18:34 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr(const char *string)
{
	int index;

	index = 0;
	if (string == NULL)
		return (-1);
	while (string[index])
	{
		if (string[index] == '\n')
			return (index);
		index++;
	}
	if (string[index] == '\n')
		return (index);
	return (-1);
}

char	*ft_substr(char const *s, int start, size_t len)
{
	char	*ptr;
	size_t	index;
	int		i;

	if (s == NULL)
		return (NULL);
	if (start > myft_strlen(s) || len == 0)
		return (0);
	i = 0;
	index = start;
	if ((ptr = (char*)malloc((len + 1) * sizeof(char))))
	{
		while (i < (int)(len) && s[index] != '\0')
			ptr[i++] = s[index++];
		ptr[i] = '\0';
		return (ptr);
	}
	return (0);
}

char	*free_malloc(char **static_line, char **buff, int sign, int index)
{
	char *tmp;
	char *help;
	char *tt;

	help = NULL;
	tmp = NULL;
	if (sign == 0)
	{
		help = *static_line;
		*static_line = myft_strjoin(*static_line, *buff);
		free(help);
		help = NULL;
		return (*static_line);
	}
	tt = tmp;
	if (index == 0)
		tmp = ft_strdup("");
	else
		tmp = ft_substr(*static_line, 0, index);
	free(tt);
	help = *static_line;
	*static_line = ft_substr(*static_line, index + 1,
			myft_strlen(*static_line) - index);
	free(help);
	return (tmp);
}

int		ft_return(int index, int sign, char **static_line, char **buff)
{
	free(*buff);
	*buff = 0;
	if (index >= 0)
		return (1);
	if (index < 0 && sign == 0)
	{
		*static_line = NULL;
		return (0);
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	int			index;
	int			sign;
	char		*buff;
	static char	*static_line;

	if (static_line == NULL)
		static_line = ft_strdup("");
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))) ||
			BUFFER_SIZE <= 0 || line == NULL || fd < 0)
		return (-1);
	while ((sign = read(fd, buff, BUFFER_SIZE)) || (sign + 1))
	{
		buff[sign] = '\0';
		if (sign != 0)
			static_line = free_malloc(&static_line, &buff, 0, 0);
		if ((index = ft_strchr(static_line)) >= 0 || sign == 0)
		{
			if (index < 0 && sign == 0)
				*line = free_malloc(&static_line, 0, 1, myft_strlen(static_line));
			else
				*line = free_malloc(&static_line, 0, 1, index);
			return (ft_return(index, sign, &static_line, &buff));
		}
	}
	return (-1);
}
