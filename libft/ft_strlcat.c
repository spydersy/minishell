/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ghem <ael-ghem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:04:14 by ael-ghem          #+#    #+#             */
/*   Updated: 2019/10/23 19:00:52 by ael-ghem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		len;
	size_t		n;

	d = dst;
	s = src;
	n = size;
	while (n-- && *d != '\0')
		d++;
	len = d - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1 && n--)
			*d++ = *s;
		s++;
	}
	*d = '\0';
	return (len + (s - src));
}
