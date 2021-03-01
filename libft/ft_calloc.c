/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ghem <ael-ghem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:04:04 by ael-ghem          #+#    #+#             */
/*   Updated: 2019/10/23 15:32:55 by ael-ghem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *ret;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	if (!(ret = malloc(count * size)))
		return (0);
	ft_bzero(ret, count * size);
	return (ret);
}
