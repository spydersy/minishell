/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ghem <ael-ghem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:33:04 by ael-ghem          #+#    #+#             */
/*   Updated: 2019/10/23 15:37:02 by ael-ghem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list *node;

	if (!(node = (t_list*)malloc(sizeof(t_list))))
		return (0);
	node->content = content;
	node->next = 0;
	return (node);
}
