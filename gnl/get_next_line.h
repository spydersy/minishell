/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:18:43 by abelarif          #+#    #+#             */
/*   Updated: 2021/02/19 16:05:45 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFFER_SIZE 100

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/libft.h"

int		get_next_line(int fd, char **line);
int		ft_checkvalue(int read_value, char **line, char *rest, char *buf);
char	*free_all(char *buf, char **rest);
int		check_nl(const char *rest);
char	*strjoin(char **rest, char *buf);
char	*r_r(char *rest, int index_nl);
char	*r_l(char *rest, int index_nl);

#endif
