/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 00:43:18 by marvin            #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					get_curren_flags_int(t_flags *f, t_prin *p)
{
	f->minus = ft_flag(p->flag, "-");
	f->plus = ft_flag(p->flag, "+");
	f->zero = ft_flag(p->flag, "0");
	f->space = ft_flag(p->flag, " ");
	f->zero && f->minus ? f->zero = FALSE : 0;
	f->space && f->plus ? f->space = FALSE : 0;
	f->all_flags = (f->zero && f->plus && f->minus && f->space) ? 1 : 0;
	f->zero_space = (f->zero && f->space) ? 1 : 0;
	f->plus_zero = (f->zero && f->plus) ? 1 : 0;
	f->plus_minus = (!f->zero && f->plus && f->minus && !f->space) ? 1 : 0;
}

static void				ft_wwrite_int(char *tmm, int mi, t_prin *p)
{
	t_flags		f;

	f.len = (int)ft_strlen(tmm);
	if (p->flag != NULL && p->flag[0] != 'j' && p->flag[0] != 'z')
	{
		get_curren_flags_int(&f, p);
		if (f.plus && !f.minus && !f.zero && !f.space)
			int_only_plus(p, mi, tmm);
		else if (!f.plus && f.minus && !f.zero && !f.space)
			int_only_minus(p, mi, tmm);
		else if (!f.plus && !f.minus && f.zero && !f.space)
			int_only_zero(p, mi, tmm);
		else if (!f.plus && !f.minus && !f.zero && f.space)
			int_only_space(p, mi, tmm);
		else if (f.all_flags)
			int_all_flags(p, mi, tmm);
		else if (f.zero_space)
			int_zero_space(p, &f, mi, tmm);
		else if (f.plus_zero)
			int_plus_zero(p, &f, mi, tmm);
		else if (f.plus_minus)
			int_all_flags(p, mi, tmm);
	}
	else
		int_print_without_flag(p, mi, tmm);
}

static void				ft_write_int(char *tmm, int mi, t_prin *p)
{
	if (p->lenght[1] == 'M')
		ft_wwrite_int("8085774586302733229", mi, p);
	else
		ft_wwrite_int(tmm, mi, p);
}

static void				get_zero(const char *tmp, int len, t_prin *p, int mi)
{
	char	*tmm;
	int		i;

	i = 0;
	tmm = ft_strnew((size_t)p->strike);
	p->strike -= len;
	while (tmp[i] != 0)
	{
		tmm[i] = tmp[i];
		i++;
	}
	while (p->strike > 0)
	{
		tmm[i] = '0';
		i++;
		p->strike--;
	}
	ft_write_int(tmm, mi, p);
	ft_strdel(&tmm);
}

void					dprint(t_prin *p)
{
	intmax_t	res;
	char		tmp[50];
	int			i;
	int			minus;

	res = ft_get_res(p);
	tim(p);
	i = 0;
	ft_bzero(tmp, 50);
	minus = FALSE;
	(res < 0) ? (minus = TRUE) : 0;
	res = (minus) ? (res * (-1)) : res;
	while (42)
	{
		tmp[i] = res % 10 + '0';
		res /= 10;
		if (++i && res <= 0)
			break ;
	}
	if (ft_a_null(tmp, (int)ft_strlen(tmp)) && (p->strike == 0))
		print_null_sp(p->width - ft_strlen(tmp) + 1, ' ');
	else if (p->strike > (int)ft_strlen(tmp))
		get_zero(tmp, (int)ft_strlen(tmp), p, minus);
	else
		ft_write_int(tmp, minus, p);
}
