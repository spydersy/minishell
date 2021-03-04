/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_handling_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 20:34:22 by abelarif          #+#    #+#             */
/*   Updated: 2021/03/04 03:37:45 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_quote				set_quote_value(char quote_type, t_quote to_quote)
{
	t_quote		quote;

	quote.double_quote = to_quote.double_quote;
	quote.simple_quote = to_quote.simple_quote;
	if(to_quote.double_quote == false && to_quote.simple_quote == false)
	{
		if (quote_type == 39)
			quote.simple_quote = true;
		else
			quote.double_quote = true;
	}
	else if ((to_quote.simple_quote == true) && (quote_type == 39))
			quote.simple_quote = false;
	else if ((to_quote.double_quote == true) && (quote_type == 34))
			quote.double_quote = false;
	return (quote);
}

int					count_separators(char *line, char separator)
{
	int				i;
	t_quote			quote;
	int				c;

	c = 0;
	i = -1;
	quote.simple_quote = false;
	quote.double_quote = false;
	while (line[++i])
	{
		if ((line[i] == 39 || line[i] == 34))
			if (i >= 1 && line[i - 1] != '\\')
				quote = set_quote_value(line[i], quote);
		if (separator == ';' && line[i] == ';' && line[i + 1] == ';')
			ft_error("parse error near `;;'");
		else if (line[i] == separator)
			if (i >= 1 && line[i - 1] != '\\')
				if (!quote.simple_quote && !quote.double_quote)
				c++;
	}
	return (c);
}

t_separator			get_separator_index(char *line, char separator_type)
{
	t_quote			quote;
	int             i;
	int				c;
	t_separator		separator;

	i = -1;
	c = -1;
	quote.double_quote = false;
	quote.simple_quote = false;
	separator.nb_separator = count_separators(line, separator_type);
	separator.separator_index = malloc(separator.nb_separator * sizeof(int));
	if (separator.separator_index == NULL)
		ft_error(NULL);
	while (line[++i])
	{
		if ((line[i] == 39 || line[i] == 34) && i >= 1 && line[i - 1] != '\\')
			quote = set_quote_value(line[i], quote);
		else if (line[i] == separator_type && i >= 1 && line[i - 1] != '\\')
			if (!quote.simple_quote && !quote.double_quote)
				separator.separator_index[++c] = i;
	}
	return (separator);
}
