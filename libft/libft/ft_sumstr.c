/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sumstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:03:41 by masprigg          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_continuum(char *str, int a, int b, int l)
{
	int		tmp;
	int		f;

	tmp = 0;
	f = 0;
	if (a + b > 9)
		tmp = 1;
	f = (a + b) % 10;
	str[l] += f;
	(str[l] == 58) ? (tmp = 1) : 0;
	(str[l] == 58) ? (str[l] -= 10) : 0;
	str[l - 1] += tmp;
}

static char	*ft_press_str(char *str)
{
	char	*res;
	char	*begin;

	begin = str;
	while (*str == '0')
	{
		str++;
		if (*str == '\0')
		{
			ft_strdel(&begin);
			return (ft_strdup("0"));
		}
	}
	res = ft_strdup(str);
	ft_strdel(&begin);
	return (res);
}

static char	*ft_sum_str2(char *s1, char *s2)
{
	int		l1;
	int		l2;
	int		a;
	int		b;
	char	*res;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	a = 0;
	b = 0;
	res = ft_strnew(MAX(l1, l2) + 1);
	ft_memset(res, 48, MAX(l1, l2) + 1);
	while (l1 > 0 || l2 > 0)
	{
		a = (l1 > 0) ? (s1[l1 - 1] - 48) : 0;
		b = (l2 > 0) ? (s2[l2 - 1] - 48) : 0;
		ft_continuum(res, a, b, MAX(l1, l2));
		l1--;
		l2--;
	}
	return (ft_press_str(res));
}

char		*ft_sum_str(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (ft_strdup("0"));
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	if (ft_strlen(s1) > ft_strlen(s2))
		return (ft_sum_str2(s2, s1));
	else
		return (ft_sum_str2(s1, s2));
}
