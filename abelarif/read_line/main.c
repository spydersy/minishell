/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:18:54 by abelarif          #+#    #+#             */
/*   Updated: 2020/06/21 12:14:28 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

int		ft_d_quotes(int i, int quotes, int d_quotes)
{
	if (quotes)
		d_quotes = 0;
	else if (d_quotes)
		d_quotes = 0;
	else if (d_quotes == 0)
		d_quotes = i + 1;
	return (d_quotes);
}

int		ft_quotes(int i, int quotes, int d_quotes)
{
	if (d_quotes)
		quotes = 0;
	else if (quotes)
		quotes = 0;
	else if (quotes == 0)
		quotes = i + 1;
	return (quotes);
}

int		ft_sym(int id, int i, int nb, int quotes, int d_quotes)
{
	char	sym;

	if (id  == 1)
		sym = ';';
	if (quotes || d_quotes)
		nb = nb;
	else if (quotes == 0 && d_quotes == 0)
	{
		nb++;
		if (id == 1 && g_line[i + 1] == sym)
			printf("error\n");
		if (id == 2)
			return (1);
	}
	return (nb);
}

int		get_nb_points()
{
	int		i;
	int		d_quotes;
	int		quotes;
	int		nb_points;

	nb_points = 0;
	d_quotes = 0;
	quotes = 0;
	i = 0;
	while (g_line[i])
	{
		if (g_line[i] == '\"' )
			d_quotes = ft_d_quotes(i, quotes, d_quotes);
		else if(g_line[i] == '\'')
			quotes = ft_quotes(i, quotes, d_quotes);
		else if (g_line[i] == ';')
			nb_points = ft_sym(1, i, nb_points, quotes, d_quotes);
		i++;
	}
	// (nb_points != 0) ? (nb_points++) : (nb_points = nb_points);
	return (nb_points);
}

int		get_len(int index_line)
{
	int		len;
	int		d_quotes;
	int		quotes;

	len = 0;
	quotes = 0;
	d_quotes = 0;
	while (g_line[index_line])
	{
		if (g_line[index_line] == '\"' )
			d_quotes = ft_d_quotes(index_line, quotes, d_quotes);
		else if(g_line[index_line] == '\'')
			quotes = ft_quotes(index_line, quotes, d_quotes);
		else if (g_line[index_line] == ';')
		{
			if (ft_sym(2, index_line, 0, quotes, d_quotes))
				return (len);
		}
		index_line++;
		len++;	
	}
	return (len);
	
}

void	get_commands(int nb_commands)
{
	int		i;
	int		j;
	int		index_line;
	int		len_cmd;


	index_line = 0;
	i = 0;
	j = 0;
	g_all_commands = malloc(sizeof(char *)  * (nb_commands + 1));
	while (i <= nb_commands)
	{
		len_cmd = get_len(index_line);
		printf("len (%d) : %d\n", i, len_cmd);
		g_all_commands[i] = malloc(sizeof(char) * (len_cmd + 1));
		while (j < len_cmd)
		{
			g_all_commands[i][j] = g_line[index_line];
			index_line++;
			j++;
		}
		g_all_commands[i][j] = '\0';
		printf(">>%d<< : >>%s<<\n\n", i, g_all_commands[i]);
		i++;
		j = 0;
		index_line++;
	}
	g_all_commands[i] = NULL;
}

// void	split_by_pipes()
// {
// 	int		i;

// 	i = 0;
// 	while ()
// 	{
		
// 	}
// }

int		main()
{
	int		nb_commands;

	nb_commands = 0;
	g_line = "clear ; gcc;";
	nb_commands = get_nb_points();
	
	printf("%d\n", nb_commands);
	printf("\n************************************\n\n");

	get_commands(nb_commands);
	// split_by_pipes();

	return (0);
}