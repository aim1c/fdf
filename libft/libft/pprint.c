/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 23:20:49 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				get_curren_flags_pointer(t_flags *f, t_prin *p)
{
	if (p->flag != NULL)
	{
		f->minus = ft_flag(p->flag, "-");
		f->plus = FALSE;
		f->zero = ft_flag(p->flag, "0");
		f->space = FALSE;
		f->minus || p->strike >= 0 ? f->zero = FALSE : 0;
	}
}

static void				continue_to_shit(t_prin *p, char *tmm, t_flags *f)
{
	p->strike > f->len ? f->len = p->strike : 0;
	p->strike < 0 ? p->strike = 0 : 0;
	f->minus ? (sprint("0x", 2)) : print_null_sp(p->width - f->len - 6, ' ');
	f->minus ? print_null_sp(p->strike, '0') : (sprint("0x", 2));
	f->minus ? ft_putstr_rev(tmm, f->len - p->strike)
						: print_null_sp(p->strike, '0');
	f->minus ? print_null_sp(p->width - f->len - 6, ' ')
						: ft_putstr_rev(tmm, f->len - p->strike);
}

void					write_this_shit(t_prin *p, char *tmm)
{
	t_flags		f;

	f.len = (int)ft_strlen(tmm);
	get_curren_flags_pointer(&f, p);
	if (p->width - 6 <= f.len && p->strike <= f.len)
	{
		sprint("0x", 6);
		ft_putstr_rev(tmm, f.len);
	}
	else if (f.zero && p->strike == -1 && p->width - 6 > f.len)
	{
		sprint("0x", 2);
		print_null_sp(p->width - f.len - 6, '0');
		ft_putstr_rev(tmm, f.len);
	}
	else
		continue_to_shit(p, tmm, &f);
}

char					table_hex(int i, char spec)
{
	char	a;

	if (i >= 0 && i < 10)
		return (i + '0');
	else if (i == 10)
		a = 'a';
	else if (i == 11)
		a = 'b';
	else if (i == 12)
		a = 'c';
	else if (i == 13)
		a = 'd';
	else if (i == 14)
		a = 'e';
	else if (i == 15)
		a = 'f';
	if (spec == 'X')
		a = ft_toupper(a);
	return (a);
}

void					pprint(t_prin *p)
{
	size_t			number;
	char			tmp[30];
	int				i;

	number = va_arg(p->ap, size_t);
	i = 0;
	tim(p);
	if (number == 0)
	{
		sprint("0x0", 3);
		return ;
	}
	ft_bzero(tmp, 30);
	while (42)
	{
		tmp[i] = table_hex((number % 16), p->spec);
		number /= 16;
		if (++i && number <= 0)
			break ;
	}
	write_this_shit(p, tmp);
}
