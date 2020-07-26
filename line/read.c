/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:40:28 by abelarif          #+#    #+#             */
/*   Updated: 2020/07/26 19:49:16 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"
#include "get_next_line.h"

int				manipquotes(int quote, int quote_type)
{
	if (quote_type == '\'' && !(quote % 2) && quote >= 10)
		return (quote);
	else if (quote_type == '\'' && quote % 2 == 1)
		return (quote - 1);
	if (quote_type == '\'' && !(quote % 2) && quote < 10)
		return (quote + 1);
	else if (quote_type == '\"' && (quote % 2))
		return (quote);
	else if (quote_type == '\"' && !(quote % 2) && quote < 10)
		return (quote + 10);
	else if (quote_type == '\"' && quote == 10)
		return (0);
	return (quote);
}

char			*get_split(char *line, int split_by)
{
	static int	i = -1;
	static int	old;
	static int	split = 59;
	int			quote;

	quote = 0;
	old = i + 1;
	if (split != split_by)
	{
		split = split_by;
		i = -1;
		old = i + 1;
	}
	while (line[++i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			quote = manipquotes(quote, line[i]);
		if (line[i] == split_by && quote == 0)
			return (ft_substr(line, old, i - old));
	}
	if (!line[i] && i == old)
		return (NULL);
	else if (!line[i] && i != old)
		return (ft_substr(line, old, i));
}

t_splitpoint	*add_split_point(char *str, t_splitpoint *split_point)
{
	t_splitpoint	*newsplit;

	newsplit = malloc(sizeof(t_splitpoint));
	newsplit->long_command = str;
	newsplit->next = split_point;
	return (newsplit);
}

void			show_all(t_splitpoint *split_point)
{
	int	i;

	i = 0;
	while (split_point)
	{
		printf("%s\n", split_point->long_command);
		split_point = split_point->next;
		i++;
	}
	printf("%d\n", i);
}

int				ft_line_manipulation(char *line)
{
	t_splitpoint	*split_point;
	static int		nb;
	char			*long_command;

	split_point = NULL;
	while ((long_command = get_split(line, ';')) != NULL)
	{
		split_point = add_split_point(long_command, split_point);
		nb++;
	}
	list_reverse(&split_point);
	show_all(split_point);
	ft_split_pipe(split_point);
}

int				ft_error(int error)
{
	printf("%Error\n");
	return (-1);
}

int				main()
{
	char		*line;

	if (get_next_line(0, &line) == -1)
		return (ft_error(-1));
	if (ft_line_manipulation(line) == -1)
		return (ft_error(-1));
	return (0);
}
