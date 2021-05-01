/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:28:10 by abelarif          #+#    #+#             */
/*   Updated: 2021/05/01 08:46:39 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//////////////////////////////////////////////////////////////////////////////////

int                 count_bs(char *line, int index)
{
    int     c;

    c = 0;
    while (index-- >= 0)
    {
        if (line[index] == '\\')
            c++;
        else
            break ;
    }
    return (c);
}

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
	quote = init_quote();
	 
	while (line[++i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			quote = set_quote_value(line[i], quote);
		else if ((line[i] == '>' || line[i] == '<'))
		{
			if ((count_bs(line, i) % 2 == 0
			&& !quote.d_quote && !quote.s_quote) || i == 0)
			{
				c++;
				i = skip_redirections(line , i);
				if (!line[i])
					break ;
			}
		}
	}
	return (c);
}

int		*redirection_index(char *line, int nb)
{
	int			i;
	int			*index;
	t_quote		quote;
	int			c;

	c = -1;
	i = -1;
	quote = init_quote();
	if (!(index = malloc(sizeof(int) * nb)))
		ft_error("malloc");
	while (line[++i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			quote = set_quote_value(line[i], quote);
		else if ((line[i] == '>' || line[i] == '<')
		&& ((count_bs(line, i) % 2 == 0
		&& !quote.d_quote && !quote.s_quote) || i == 0))
		{
			index[++c] = i;
			i = skip_redirections(line , i);
			if (!line[i])
				break ;
		}
	}
	return (index);
}

int			*redirection_type(char *line, int *index, int nb)
{
	int		i;
	int		c;
	int		*type;

	i =-1;
	c = -1;
	if (!(type = malloc(sizeof(int) * nb)))
		ft_error("malloc");
	while (++i < nb)
	{
		if (line[index[i]] == '<')
		{
			type[++c] = REDI0;
		}
		else if (line[index[i]] == '>' && line[index[i] + 1] == '>')
		{
			type[++c] = REDO1;
		}
		else if (line[index[i]] == '>' && line[index[i] + 1] != '>')
		{
			type[++c] = REDO0;
		}
	}
	return (type);
}

//////////////////////////////////////////////////////////////////////////////////

int			count_words(char *line, int nb_redir, int *redir_index, int *redir_type)
{
	int		i;
	t_quote	quote;

	i = -1;
	quote = init_quote();
	while (line[++i])
	{
		
	}
	if (line || nb_redir || redir_index[0] || redir_type[0])
	{

	}
	return 0;	
}

// void		print_redir(int type)
// {
	// if (type == REDI0)
		// printf("type : REDI0 < \n");
	// else if (type == REDO0)
		// printf("type : REDO0 > \n");
	// else if (type == REDO1)
		// printf("type : REDO1 >> \n");
// }

t_words		extract_content(char *line)
{
	t_backslash		backslash;
	t_words			words;

	backslash.nb_backslash = count_bslash(line);
	backslash.backslash_index = get_bslash_index(line, backslash.nb_backslash);
	words.nb_redirection = count_redirection(line);
	words.redir_index = redirection_index(line, words.nb_redirection);
	words.types = redirection_type(line, words.redir_index, words.nb_redirection);
	words.nb_words = words.nb_redirection + count_words(line, words.nb_redirection, words.redir_index, words.types);

	// int		i = -1;
	// while (++i < words.nb_redirection)
	// {
		// print_redir(words.types[i]);
	// }

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