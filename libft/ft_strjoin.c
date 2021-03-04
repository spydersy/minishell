/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ghem <ael-ghem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:35:13 by ael-ghem          #+#    #+#             */
/*   Updated: 2019/10/16 16:47:38 by ael-ghem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len_s1;
	size_t	len_s2;

	ret = NULL;
	if (s1)
	{
		len_s1 = ft_strlen(s1);
		if (s2 == NULL)
			return (ret = ft_strdup(s1));
		len_s2 = ft_strlen(s2);
		ret = (char *)ft_calloc(sizeof(char), len_s1 + len_s2 + 1);
		if (ret)
		{
			ft_strlcpy(ret, s1, len_s1 + 1);
			ft_strlcat((ret + len_s1), s2, len_s2 + len_s1 + 1);
		}
	}
	return (ret);
}
