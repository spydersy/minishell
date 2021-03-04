/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ghem <ael-ghem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:54:28 by ael-ghem          #+#    #+#             */
/*   Updated: 2019/10/19 16:51:31 by ael-ghem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_assign(int cf, int cd, char const *s)
{
	char	*ret;

	ret = NULL;
	if (cf >= (int)ft_strlen(s))
	{
		if (!(ret = (char*)malloc(1)))
			return (NULL);
		*ret = '\0';
		return (ret);
	}
	else if ((cf + cd) != 0 && cf != (int)ft_strlen(s))
	{
		if ((ret = (char *)ft_calloc(ft_strlen(s)
		- (cd + cf) + 1, sizeof(char))))
			ft_strlcpy(ret, (s + cd), (ft_strlen(s) - (cd + cf)) + 1);
	}
	else
		ret = ft_strdup(s);
	return (ret);
}

char		*ft_strtrim(char const *s, char const *set)
{
	int		len;
	int		cd;
	int		cf;

	if (!s)
		return (NULL);
	if (!set)
		return (ft_strdup(s));
	cd = 0;
	cf = 0;
	len = (ft_strlen(s) - 1);
	while (ft_strchr(set, s[cd]))
		cd++;
	while (ft_strchr(set, s[len]))
	{
		len--;
		cf++;
	}
	return (ft_assign(cf, cd, s));
}
