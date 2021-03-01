/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ghem <ael-ghem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:09:37 by ael-ghem          #+#    #+#             */
/*   Updated: 2019/11/01 21:37:26 by ael-ghem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		get_rest(char *buf, char *save)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!buf)
		return ;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	while (buf[i])
		save[j++] = buf[i++];
	save[j] = '\0';
}

static void		get_line(char **line, char *rest)
{
	int			i;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	*line = ft_substr(rest, 0, i);
}

static int		read_to_buf(int fd, char **line, int *ret)
{
	char	*tmp;
	char	*buf;

	*ret = 1;
	while (ft_strchr(*line, '\n') == NULL && *ret != 0)
	{
		if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		if ((*ret = read(fd, buf, BUFFER_SIZE)) < 0)
			return (-1);
		buf[*ret] = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
		free(buf);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	rest[1025][BUFFER_SIZE + 1] = {""};
	int			ret;
	char		*tmp;
	char		*f;

	*line = NULL;
	if (read(fd, NULL, 0) < 0 || !line || BUFFER_SIZE < 0)
		return (-1);
	if (ft_strchr(rest[fd], '\n') != NULL)
	{
		get_line(line, rest[fd]);
		get_rest(rest[fd], rest[fd]);
		return (1);
	}
	else
		*line = ft_strdup(rest[fd]);
	if (read_to_buf(fd, line, &ret) == -1)
		return (-1);
	f = *line;
	tmp = ft_strdup(*line);
	free(f);
	get_rest(tmp, rest[fd]);
	get_line(line, tmp);
	free(tmp);
	return ((ret > 0) ? 1 : 0);
}
