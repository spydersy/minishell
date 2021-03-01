/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:32:35 by ael-ghem          #+#    #+#             */
/*   Updated: 2021/02/21 18:15:40 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		i;
	// t_list	*tmp;

	i = 0;
	// tmp = lst;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
