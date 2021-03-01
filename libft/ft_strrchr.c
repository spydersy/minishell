/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ghem <ael-ghem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:22:16 by ael-ghem          #+#    #+#             */
/*   Updated: 2019/10/23 15:42:43 by ael-ghem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ptr;

	i = -1;
	ptr = 0;
	while (s[++i])
	{
		if (s[i] == c)
			ptr = (char*)&s[i];
	}
	if (s[i] == c)
		return ((char*)&s[i]);
	return ((char*)ptr);
}
