/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigpart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 22:23:10 by masprigg          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_tpower(size_t n)
{
	size_t	res;

	res = 1;
	while (n)
	{
		res *= 2;
		n--;
	}
	return (res);
}

static size_t	ft_fromb_tint(char *str)
{
	size_t	b;
	size_t	i;

	b = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		b += (str[i] - 48) * ft_tpower(ft_strlen(str) - i - 1);
		i++;
	}
	return (b);
}

void			ft_setresult(char *mantis, t_double *suka)
{
	char	*res;
	char	*tmp;
	char	*tmp2;
	char	*lowres;
	int		ex;

	ex = ft_fromb_tint(suka->exp) - EX0 + 1;
	res = ft_strnew(1);
	ft_memset(res, 48, 1);
	while (--ex >= 0 && *mantis)
	{
		tmp2 = ft_mult_str2(*mantis - 48, ex);
		tmp = ft_sum_str(res, tmp2);
		ft_strdel(&res);
		ft_strdel(&tmp2);
		res = ft_strdup(tmp);
		ft_strdel(&tmp);
		mantis++;
	}
	lowres = ft_make_small(mantis, ex);
	suka->res = ft_strdup(res);
	ft_strike(suka, lowres);
	ft_strdel(&res);
	ft_strdel(&lowres);
}

void			ft_set_lresult(char *mantis, t_double *suka)
{
	char	*res;
	char	*tmp;
	char	*tmp2;
	char	*lowres;
	int		ex;

	ex = ft_fromb_tint(suka->exp) - EX1 + 1;
	res = ft_strnew(1);
	ft_memset(res, 48, 1);
	while (--ex >= 0 && *mantis)
	{
		tmp2 = ft_mult_str2(*mantis - 48, ex);
		tmp = ft_sum_str(res, tmp2);
		ft_strdel(&res);
		ft_strdel(&tmp2);
		res = ft_strdup(tmp);
		ft_strdel(&tmp);
		mantis++;
	}
	lowres = ft_make_small(mantis, ex);
	suka->res = ft_strdup(res);
	ft_strike(suka, lowres);
	ft_strdel(&res);
	ft_strdel(&lowres);
}
