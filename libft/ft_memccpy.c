/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ghem <ael-ghem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:49:11 by ael-ghem          #+#    #+#             */
/*   Updated: 2019/10/21 15:34:19 by ael-ghem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;
	size_t			i;

	i = -1;
	pd = (unsigned char*)dst;
	ps = (unsigned char*)src;
	while (++i < n)
	{
		pd[i] = ps[i];
		if (ps[i] == (unsigned char)c)
			return (&pd[i + 1]);
	}
	return (NULL);
}
