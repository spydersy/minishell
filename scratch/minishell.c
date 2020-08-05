/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 20:59:36 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/05 10:16:00 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	type_prompt()
{
	static int	first_time = 1;

	if (first_time == 1)
	{
		ft_putstr_fd("", 1);
		first_time = 0;
	}
	ft_putstr_fd("MINISHELL $ ", 1);
}

int		check_exit()
{
	int		i;

	i = -1;
	while (g_line[++i])
	{
		if (!(g_line[i] == ' ' || g_line[i] == '\t'))
			break;
	}
	if (ft_strncmp("exit", g_line + i, 4) != 0)
		return (0);
	i += 3;
	while (g_line[++i])
	{
		if (!(g_line[i] == ' ' || g_line[i] == '\t'))
			return (0);
	}
	return (1);
}

int		skip_line()
{
	int		i;

	i = -1;
	while (g_line[++i])
	{
		if (!(g_line[i] == ' ' || g_line[i] == '\t'))
			return (0);
	}
	return (1);
}

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

char			*get_split(char *line, int c)
{
	static int	i = -1;
	static int	old;
	int			quote;

	quote = 0;
	old = i + 1;
	while (line[++i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			quote = manipquotes(quote, line[i]);
		if (line[i] == c && quote == 0)
			return (ft_substr(line, old, i - old));
	}
	if (!line[i] && i == old)
	{
		i = -1;
		return (NULL);
	}
	else if (!line[i] && i != old)
		return (ft_substr(line, old, i));
}

t_bcommand		*add_bcommand(char *str, t_bcommand *g_bcommand)
{
	t_bcommand		*newbcommand;

	if ((newbcommand = malloc(sizeof(t_bcommand))) == NULL)
		ft_error();
	newbcommand->bcommand = str;
	newbcommand->next = g_bcommand;
	return (newbcommand);
}

listb_reverse(t_bcommand **g_bcommand)
{
	t_bcommand	*prev;
	t_bcommand	*current;
	t_bcommand	*next;

	prev = NULL;
	next = NULL;
	current = *g_bcommand;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*g_bcommand = prev;
}


void		manip_line()
{
	static int		nb;
	char			*bcommand;

	g_bcommand = NULL;
	while ((bcommand = get_split(g_line, ';')) != NULL)
	{
		if ((g_bcommand = add_bcommand(bcommand, g_bcommand)) == NULL)
			ft_error();
		nb++;
	}
	listb_reverse(&g_bcommand);
	
}

int		main()
{
	pid_t	child;

	while (1)
	{
		type_prompt();
		get_next_line(1, &g_line);
		if (check_exit() == 1)
		{
			free_all();
			exit(0);
		}
		if (skip_line() == 0)
		{
			if (-1 == (child = fork()))
				ft_error();
			if (child == 0)
			{
				manip_line()
			}
		}
	}
	return (0);
}

// void	type_prompt()
// {
// 	static int	first_time = 1;
// 	if (first_time == 1)
// 	{
// 		write(1, "", ft_strlen(""));
// 		first_time = 0;
// 	}
// 	write (1, "MINISHELL $ ", ft_strlne("MINISHELL $ "));
// }

// int		check_exit()
// {
// 	int		i;

// 	i = -1;
// 	while (g_line[++i])
// 	{
// 		if (!(g_line[i] == ' ' || g_line[i] == '\t'))
// 			break;
// 	}
// 	if (ft_strncmp("exit", g_line + i, 4) != 0)
// 		return (0);
// 	i += 3;
// 	while (g_line[++i])
// 	{
// 		if (!(g_line[i] == ' ' || g_line[i] == '\t'))
// 			return (0);
// 	}
// 	return (1);
// }

// int		skip_line()
// {
// 	int		i;

// 	i = -1;
// 	while (g_line[++i])
// 	{
// 		if (!(g_line[i] == ' ' || g_line[i] == '\t'))
// 			return (0);
// 	}
// 	return (1);
// }

// int		add_bcommnad()
// {
	
// }

// int		manip_line()
// {
// 	int			i;
// 	t_bcommand	*bcommand;

// 	bcommand = NULL;
// 	i = -1;
// 	if (add_bcommand() == -1)
	
// }

// int		main()
// {
// 	pid_t		child;

// 	while (1)
// 	{
// 		type_prompt();
		
// 		if (get_next_line(0, &g_line) == -1)
// 		{
// 			ft_error();
// 			return (-1);
// 		}
// 		if (check_exit() == 1)
// 			break;
// 		else if (skip_line() != 1)
// 		{
// 			if (-1 == (child = fork()))
// 				ft_strerror(errno);
// 			if (child == 0)
// 			{
// 				manip_line();
// 			}
// 		}
// 	}
// 	return (0);
// }