/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:18:58 by abelarif          #+#    #+#             */
/*   Updated: 2020/06/21 12:07:59 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef READ_H

# define READ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// typedef struct commands
// {
// 	int		nb_points;
// 	int		nb_pipes;
// 	int		nb_cmds;
// 	int		
// } t_commands;

// t_commands	g_commands;

typedef struct cmd_details
{
	int		nb_pipes;
	char	**cmd;
	char	**args;
	char	**opts;
	int		*redirections;
	char	**redirection_to;
}	t_cmd_details;

char		*g_line;
char		**g_all_commands;

# endif