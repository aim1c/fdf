/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:06:38 by masprigg          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int	ft_nbrlen(int64_t n)
{
	unsigned long long	p;
	int					l;

	l = 0;
	p = (unsigned long long)(n < 0) ? (n * (-1)) : n;
	if (p == 0)
		l++;
	if (n < 0)
		l++;
	while (p)
	{
		p /= 10;
		l++;
	}
	return (l);
}

char		*ft_itoa(long long n)
{
	int					len;
	int					l;
	char				*itoa;
	unsigned long long	p;

	if ((size_t)n == (size_t)(-1))
		return (ft_strdup("-9223372036854775808"));
	len = ft_nbrlen(n);
	l = len;
	p = (unsigned long long)(n < 0) ? (n * (-1)) : n;
	if (!(itoa = (char*)malloc(sizeof(*itoa) * (len + 1))))
		return (NULL);
	if (n < 0)
		itoa[0] = '-';
	if (p == 0)
		itoa[0] = 48;
	while (len--)
	{
		if (itoa[len] != '-')
			itoa[len] = p % 10 + 48;
		p /= 10;
	}
	itoa[l] = '\0';
	return (itoa);
}
