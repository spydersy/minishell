/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ghem <ael-ghem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:56:04 by ael-ghem          #+#    #+#             */
/*   Updated: 2019/10/23 15:42:03 by ael-ghem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	i = -1;
	while (++i < n && (s1[i] || s2[i]))
	{
		if ((int)s1[i] < 0 || (int)s2[i] < 0)
			return (1);
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
