/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_littlesmall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 04:03:41 by masprigg          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_make_small(char *mantis, int ex)
{
	int		n;
	char	*res;
	char	*temp;
	char	*temp2;

	n = 0;
	res = ft_strnew(1);
	ft_memset(res, 49, 1);
	temp2 = NULL;
	while (--n != ex)
		res = ft_mult_str10(res);
	while (*mantis)
	{
		res = ft_mult_str10(res);
		temp2 = ft_mult_str5((*mantis - 48), -n);
		temp = ft_sum_str(res, temp2);
		ft_strdel(&res);
		ft_strdel(&temp2);
		res = ft_strdup(temp);
		ft_strdel(&temp);
		n--;
		mantis++;
	}
	res[0] -= 3;
	return (res);
}

char	*ft_mult_str10(char *s)
{
	char	*res;

	if (!s)
	{
		s = ft_strnew(1);
		ft_memset(s, 48, 1);
	}
	else
	{
		res = ft_strnew(ft_strlen(s) + 1);
		ft_memcpy(res, s, ft_strlen(s));
		res[ft_strlen(s)] = 48;
		ft_strdel(&s);
		s = ft_strdup(res);
		ft_strdel(&res);
	}
	return (s);
}
