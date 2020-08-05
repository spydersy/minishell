/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 20:57:28 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/05 10:14:25 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdio.h> // temporare
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include "./libft/libft.h"
#include "./GNL/get_next_line.h"

typedef struct s_bcommand t_bcommand;
typedef	struct s_command t_command;

struct s_bcommand
{
	char			*bcommand;
	t_bcommand		*next;
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

char		*g_line;
t_bcommand	*g_bcommand;
t_command	*g_commamd;

#endif