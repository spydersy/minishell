/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ghem <ael-ghem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:43:38 by ael-ghem          #+#    #+#             */
/*   Updated: 2019/10/14 21:36:22 by ael-ghem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len(int n)
{
	int l;

	if (n >= 0)
		l = 1;
	else
		l = 2;
	while ((n /= 10) != 0)
		l++;
	return (l);
}

static void		ft_put_itoa(int n, char *ret)
{
	if ((n / 10) > 0)
	{
		ft_put_itoa(n / 10, ret - 1);
		*ret = (n % 10) + '0';
	}
	else
		*ret = n + '0';
}

char			*ft_itoa(int n)
{
	char	*ret;

	if (n == -2147483648)
	{
		if (!(ret = (char*)malloc(sizeof(char) * 12)))
			return (NULL);
		ft_strlcpy(ret, "-2147483648", 12);
		return (ret);
	}
	if (!(ret = (char*)malloc(sizeof(char) * (len(n) + 1))))
		return (NULL);
	*(ret + len(n)) = '\0';
	if (n < 0)
	{
		*ret = '-';
		n *= -1;
		ft_put_itoa(n, ret + len(n));
	}
	else
		ft_put_itoa(n, ret + len(n) - 1);
	return (ret);
}
