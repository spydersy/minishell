/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:28:10 by abelarif          #+#    #+#             */
/*   Updated: 2021/03/04 06:17:25 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//////////////////////////////////////////////////////////////////////////////////

int				skip_redirections(char *line, int index)
{
	int		c;
	int			i;

	i = index;
	c = 1;
	while (line[++i])
	{
		if (line[i] == line[index])
			c++;
		else
			break ;
	}
	if (line[index] == '>' && c > 2)
		ft_error("nb_redirection");
	if (line[index] == '<' && c > 1)
		ft_error("nb_redirection");
	return (i);
}

int				count_redirection(char *line)
{
	int			i;
	int			c;
	t_quote		quote;

	i = -1;
	c = 0;
	quote.simple_quote = false;
	quote.double_quote = false;
	
	while (line[++i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			quote = set_quote_value(line[i], quote);
		else if ((line[i] == '>' || line[i] == '<'))
		{
			if ((i >= 1 && line[i - 1] != '\\'
			&& !quote.double_quote && !quote.simple_quote) || i == 0)
			{
				c++;
				i = skip_redirections(line , i);
				if (!line[i])
					break ;
			}
		}
	}
	printf("         nb redirection : %d\n", c);
	return (c);
}

//////////////////////////////////////////////////////////////////////////////////

t_words		extract_content(char *line)
{
	t_backslash		backslash;
	t_words			words;

	backslash.nb_backslash = count_bslash(line);
	backslash.backslash_index = get_bslash_index(line, backslash.nb_backslash);
	words.nb_redirection = count_redirection(line);
	// words.redir_index = redirection_index(line, words.nb_redirection);
	return (words);
}

void		extract_command(char *line)
{
	int				i;
	t_separator		c_separator;
	t_words			*words;

	i = -1;
	c_separator = get_separator_index(line, '|');
	if (!(words = malloc(sizeof(t_words) * (c_separator.nb_separator + 1))))
		ft_error("malloc");
	if (c_separator.nb_separator == 0)
		c_separator.content = ft_split(line, '\0');
	else
		c_separator.content = splitSep(line, c_separator.separator_index, c_separator.nb_separator);
	while (c_separator.content[++i])
	{
		printf("     command %d : $$%s$$\n", i, c_separator.content[i]);
		words[i] = extract_content(c_separator.content[i]);
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
		printf("command line %d : $$%s$$\n", i, cl_separator.content[i]);
		extract_command(cl_separator.content[i]);
		printf("**************************************************\n\n");
	}
}