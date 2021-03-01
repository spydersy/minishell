/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:28:10 by abelarif          #+#    #+#             */
/*   Updated: 2021/03/01 16:19:03 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		extract_content(char *line)
{
	t_backslash		backslash;

	backslash.nb_backslash = count_bslash(line);
	backslash.backslash_index = get_bslash_index(line, backslash.nb_backslash);
}

void		extract_command(char *line)
{
	int				i;
	t_separator		c_separator;

	i = -1;
	c_separator = get_separator_index(line, '|');
	if (c_separator.nb_separator == 0)
		c_separator.content = ft_split(line, '\0');
	else
		c_separator.content = splitSep(line, c_separator.separator_index, c_separator.nb_separator);
	while (c_separator.content[++i])
	{
		printf("     command %d : >>%s<<\n", i, c_separator.content[i]);
		extract_content(c_separator.content[i]);
	}
}

void        extract_command_line(char *line)
{
	int				i;
	t_separator		cl_separator;
	i = -1;
	(line[0] == ';' && line[1] == ';') && (ft_error("parse error near `;;'"));
	(line[0] == ';') && (line++);
	cl_separator = get_separator_index(line, ';');
	printf("nb_separator : %d\n\n", cl_separator.nb_separator);
	if (cl_separator.nb_separator == 0)
		cl_separator.content = ft_split(line, '\0');
	else
		cl_separator.content = splitSep(line, cl_separator.separator_index, cl_separator.nb_separator);
	while (cl_separator.content[++i])
	{
		printf("\n\n**************************************************\n");
		printf("command line %d : >>%s<<\n", i, cl_separator.content[i]);
		extract_command(cl_separator.content[i]);
		printf("**************************************************\n\n");
	}
}