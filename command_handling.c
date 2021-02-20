/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:28:10 by abelarif          #+#    #+#             */
/*   Updated: 2021/02/20 06:33:45 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_quote		set_quote_value(char *line, int index, bool simple_quote, bool double_quote)
{
	t_quote		quote;

	printf("index : >>%c<< | >>%d<<\n", line[index], line[index]);
	quote.double_quote = double_quote;
	quote.simple_quote = simple_quote;
	if(double_quote == false && simple_quote == false)
	{
		if (line[index] == 39)
			quote.simple_quote = true;
		else
			quote.double_quote = true;
	}
	else if (simple_quote == true && (line[index] = 39))
			quote.simple_quote = false;
	else if (double_quote == true && (line[index] = 34))
			quote.double_quote = false;
	return (quote);
}

int					count_separators(char *line)
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
		if ((line[i] == 39 || line[i] == 34) && line[i - 1] != '\\')
		{
			printf("\nB : (s, d) : (%d, %d)\n", quote.simple_quote, quote.double_quote);
			quote = set_quote_value(line, i, quote.simple_quote, quote.double_quote);
			printf("A : (s, d) : (%d, %d)\n\n", quote.simple_quote, quote.double_quote);
		}
		if (line[i] == ';' && line[i - 1] != '\\')
		{
			if (!quote.simple_quote && !quote.double_quote)
				c++;
		}
	}
	return (c);
}

t_separator			get_separator_index(char *line)
{
	t_separator     separator;
	int             i;

	i = -1;
	separator.nb_separator = count_separators(line);
	printf("nb = %d\n", separator.nb_separator);
	// ft_error("DONE");
	separator.separator_index = malloc(separator.nb_separator * sizeof(int));
	if (separator.separator_index == NULL)
		ft_error(NULL);
	return (separator);
}

void        extract_data(char *line)
{
	t_separator		separator;

	separator = get_separator_index(line);
	if (separator.nb_separator == 0)
	{
		
	}
}