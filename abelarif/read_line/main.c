/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 18:18:54 by abelarif          #+#    #+#             */
/*   Updated: 2020/06/22 23:37:51 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

int		get_nb_splits(int c, char *str)
{
	int		i;
	int		d_quotes;
	int		quotes;
	int		nb_points;

	nb_points = 0;
	d_quotes = 0;
	quotes = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' )
			d_quotes = ft_d_quotes(i, quotes, d_quotes);
		else if(str[i] == '\'')
			quotes = ft_quotes(i, quotes, d_quotes);
		else if (str[i] == c)
			nb_points = ft_sym(c, str[i], nb_points, quotes, d_quotes);
		i++;
	}
	return (nb_points);
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
		g_all_commands[i] = malloc(sizeof(char) * (len_cmd + 1));
		while (j < len_cmd)
		{
			g_all_commands[i][j] = g_line[index_line];
			index_line++;
			j++;
		}
		g_all_commands[i][j] = '\0';
		i++;
		j = 0;
		index_line++;
	}
	g_all_commands[i] = NULL;
}

void	split_by_pipe()
{
	int		i;
	int		len_tab;
	int		nb_pipe;

	len_tab = 0;
	i = 0;
	while (g_all_commands[i] != NULL)
		len_tab++;
	g_all_details_commands = malloc(sizeof(t_all_commands) * (len_tab + 1));
	while (g_all_commands[i])
	{
		g_all_details_commands[i].nb_pipes = get_nb_splits('|', g_all_commands[i]);
		g_all_details_commands[i].cmd_details = malloc(sizeof(t_cmd_details)
		* (g_all_details_commands[i].nb_pipes + 2));
	}
}

int		main()
{
	int		nb_commands;
	int		i = 0;
	nb_commands = 0;
	g_line = "clear ; ;; gcc;";
	nb_commands = get_nb_splits(';', g_line);
	
	get_commands(nb_commands);
	split_by_pipe();
	// while (g_all_commands[i])
	// {
	// 	printf(">>%s<<\n", g_all_commands[i]);
	// 	i++;
	// }
	// printf(">>%s<<\n", g_all_commands[i]);
	return (0);
}