/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:41:44 by abelarif          #+#    #+#             */
/*   Updated: 2021/05/01 08:52:31 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <sys/errno.h>
#include "./libft/libft.h"
#include "./gnl/get_next_line.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define REDI0	9001	/*	<			*/
#define REDO0	9002	/*	>			*/
#define	REDO1	9003	/*	>>			*/
#define UNDEF	9004	/*	undefined	*/
#define CMD		9005	/*	command		*/
#define	ARGS	9006	/*	arguments	*/

typedef struct			s_quote
{
	bool            	s_quote;
	bool            	d_quote;
}               		t_quote;

typedef struct			s_backslash
{
	int					nb_backslash;
	int					*backslash_index;
}						t_backslash;

typedef	struct			s_words
{
	int					nb_words;
	int					nb_redirection;
	int					*redir_index;
	char				**words;
	int					*types;
}						t_words;

typedef struct 			s_separator
{
	int     			*separator_index;
	int     			nb_separator;
	char            	**content;
}               		t_separator;

typedef struct			s_content
{
	char				*cmd;
	char				**args;
	
}						t_content;



int						count_bslash(char *line);
int						*get_bslash_index(char *line, int nb);
int						ft_error(char *description);
int                 	count_bs(char *line, int index);
void					clear_window(void);
void					prompt(int sig);
void    				extract_command_line(char *line);
char					*read_line(void);
char					**splitSep(char *line, int *sepIndex, int nbSep);
t_quote					set_quote_value(char quote_type, t_quote to_quote);
t_quote					init_quote(void);
t_separator				get_separator_index(char *line, char separator_type);

#endif
