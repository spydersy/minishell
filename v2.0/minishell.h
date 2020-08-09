/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 11:23:23 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/08 20:03:53 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define	MINISHELL_H

#include "./libft/libft.h"
#include "./GNL/get_next_line.h"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

typedef struct s_linecommand t_linecommand;
typedef	struct s_command t_command;

struct s_linecommand
{
	char			*linecommand;
	t_linecommand	*next;
};

struct s_command
{
	char		*command;
	
	char		*cmd;
	int			mycmd;
	int			bin;

	char		**args;

	char		**opts;

	int			n_redir;
	int			*redir;
	char		**redir_to;

	t_command	*next;
};

t_linecommand					*g_linecommand;
char							*g_line;
char							**g_mycmd;
t_command						*g_command;

void							list_reverselc(t_linecommand **g_linecommand);
char                            **mysplit(char const *s, char c, char d);
int								check_exit();
void							prompt_signal();
void							ft_exit();
int								ignore_line();
int								skip_bits(char *line);
void							init_var();
void							ft_line();
void							first_split();
void							pipe_split(char *line);
char							*get_split(char *line, int split_by, int quote);
void							get_details(t_command *g_command);
int								manip_cmd(t_command *g_command);
// int								manipquotes(int quote, int quote_type);

#endif
