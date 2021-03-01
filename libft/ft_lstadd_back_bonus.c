/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ghem <ael-ghem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:41:24 by ael-ghem          #+#    #+#             */
/*   Updated: 2019/10/21 15:19:58 by ael-ghem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (*alst == (void*)0)
		(*alst) = new;
	else
	{
		if ((*alst)->next)
			ft_lstadd_back(&(*alst)->next, new);
		else
			(*alst)->next = new;
	}
}
