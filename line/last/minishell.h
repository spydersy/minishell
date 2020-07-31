/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:40:42 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/31 17:16:43 by abelarif         ###   ########.fr       */
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
t_splitpoint	*add_g_splitpt(char *str, t_splitpoint *g_splitpt);
void			list_reverse(t_splitpoint **g_splitpt);
t_command		*add_commands(char *command, t_command *g_command);
void			ft_split_pipe(t_splitpoint *g_splitpt);
void			ft_split_commands(char *long_command);
char			*get_cmd(char *command);
int				manipquotes(int quote, int quote_type);
int				skip_cmd(char *command);
int				get_end(char *s, int start);
char			**get_redir_to(char *command, int nb);
int				get_n_redir(char *command);
int				*get_redir(char *command, int n_redir);
char			**get_opts(char	*command);
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

t_splitpoint	*g_splitpt;
t_command		*g_command;
#endif
