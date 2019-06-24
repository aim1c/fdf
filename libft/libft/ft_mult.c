/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mult.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 02:30:01 by masprigg          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_mult5(char *s)
{
	int		l;
	int		tmp1;
	int		tmp2;

	l = ft_strlen(s);
	tmp1 = 0;
	tmp2 = 0;
	while (l)
	{
		tmp1 = ((s[l - 1] - 48) * 5) / 10;
		s[l - 1] = ((s[l - 1] - 48) * 5) % 10 + tmp2 + 48;
		tmp2 = tmp1;
		l--;
	}
}

static void	ft_mult2(char *s)
{
	int		l;
	int		tmp1;
	int		tmp2;

	l = ft_strlen(s);
	tmp1 = 0;
	tmp2 = 0;
	while (l)
	{
		tmp1 = ((s[l - 1] - 48) * 2) / 10;
		s[l - 1] = ((s[l - 1] - 48) * 2) % 10 + tmp2 + 48;
		tmp2 = tmp1;
		l--;
	}
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
			free(begin);
			return (ft_strdup("0"));
		}
	}
	res = ft_strdup(str);
	free(begin);
	return (res);
}

char		*ft_mult_str5(int m, int exp)
{
	char	*res;

	if (!m)
		return (ft_strnew(0));
	if (!exp)
		return (ft_strdup("1"));
	res = ft_strnew(exp);
	ft_memset(res, 48, exp);
	res[exp - 1]++;
	while (exp)
	{
		ft_mult5(res);
		exp--;
	}
	return (ft_press_str(res));
}

char		*ft_mult_str2(int m, int exp)
{
	char	*res;

	if (!m)
		return (ft_strnew(0));
	if (!exp)
		return (ft_strdup("1"));
	res = ft_strnew(exp);
	ft_memset(res, 48, exp);
	res[exp - 1]++;
	while (exp)
	{
		ft_mult2(res);
		exp--;
	}
	return (ft_press_str(res));
}
