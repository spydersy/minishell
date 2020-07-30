/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:40:42 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/30 11:16:42 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"

typedef struct s_splitpoint t_splitpoint;
typedef	struct s_command t_command;

int				ft_error(int error);
int				ft_line_manipulation(char *line);
char			*get_split(char *line, int split_by);
t_splitpoint	*add_split_point(char *str, t_splitpoint *split_point);
void			list_reverse(t_splitpoint **split_point);
t_command		*add_commands(char *command, t_command *all_commands);
void			ft_split_pipe(t_splitpoint *split_point);
void			ft_split_commands(char *long_command);
char			*get_cmd(char *command);
int				manipquotes(int quote, int quote_type);
int				skip_cmd(char *command);
int				get_end(char *s, int start);

struct s_splitpoint
{
	char		*long_command;
	t_splitpoint	*next;
};

struct s_command
{
	char		*command;
	char		*cmd;
	int			bin;
	char		**args;
	char		**opts;
	int			n_redir;
	int			*redir;
	char		**redir_to;
	t_command	*next;
};

#endif
