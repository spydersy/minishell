/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 10:17:16 by abelarif          #+#    #+#             */
/*   Updated: 2020/08/10 10:38:06 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		main()
{
	char	*buf;

	buf = NULL;
	buf = getcwd(buf, 500);
	if (buf == NULL)
	{
		ft_putendl_fd(strerror(errno), 2);
		return (-1);
	}
	ft_putendl_fd(buf, 1);
	return (0);
}