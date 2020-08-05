/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 10:36:10 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/05 11:08:08 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		main()
{
	char	*buf;
	char	*mycwd;

	buf = NULL;
	mycwd = getcwd(buf, 1000);
	if (mycwd == NULL)
	{
		ft_putstr_fd(strerror(errno), 2);
		return (0);
	}
	ft_putstr_fd(mycwd, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}