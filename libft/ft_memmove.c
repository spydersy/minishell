/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ghem <ael-ghem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:03:44 by ael-ghem          #+#    #+#             */
/*   Updated: 2019/10/21 15:41:01 by ael-ghem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pd;
	unsigned char	*ps;
	int				i;
	int				add;

	if (!dst && !src)
		return (NULL);
	i = 0;
	add = 1;
	pd = (unsigned char*)dst;
	ps = (unsigned char*)src;
	if (dst == src)
		return (dst);
	if (!len)
		return (dst);
	i = (pd > ps && pd < ps + len) ? len - 1 : 0;
	add = (i != 0) ? -1 : 1;
	while (len--)
	{
		pd[i] = ps[i];
		i += add;
	}
	return (dst);
}
