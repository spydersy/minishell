/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 03:12:37 by eel-orch          #+#    #+#             */
/*   Updated: 2020/07/18 20:00:11 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 42

int		get_next_line(int fd, char **line);
int		myft_strlen(const char *tab);
char	*myft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);

#endif
