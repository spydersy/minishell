/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:18:58 by abelarif          #+#    #+#             */
/*   Updated: 2020/06/22 17:56:12 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef READ_H

# define READ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_d_quotes(int i, int quotes, int d_quotes);
int		ft_quotes(int i, int quotes, int d_quotes);
int		ft_sym(int id, char *str, int nb, int quotes, int d_quotes);
int		get_len(int index_line);

typedef struct commands
{
	int		nb_points;
	int		nb_pipes;
	int		nb_cmds;
} t_commands;

// t_commands	g_commands;



typedef struct cmd_details
{
	char	**cmd;
	char	**args;
	char	**opts;
	int		*redirections;
	char	**redirection_to;
	
}	t_cmd_details;

typedef	struct all_commands
{
	t_cmd_details	*cmd_details;
	int				nb_pipes;

}	t_all_commands;

char			*g_line;
char			**g_all_commands;
t_all_commands	*g_all_details_commands;

# endif