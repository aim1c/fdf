/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_plus2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 03:14:40 by masprigg          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_zero_space(t_prin *p, t_flags *f, int mi, char *tmm)
{
	char	a;

	if (!f->minus)
	{
		p->width--;
		a = (p->strike == -1) ? '0' : ' ';
		!mi && !f->plus ? sprint(" ", 1) : 0;
		mi && a == '0' ? sprint("-", 1) : 0;
		!mi && a == '0' && f->plus ? sprint("+", 1) : 0;
		print_null_sp(p->width - (int)ft_strlen(tmm), a);
		!mi && a == ' ' && f->plus ? sprint("+", 1) : 0;
		mi && a == ' ' ? sprint("-", 1) : 0;
		ft_putstr_rev(tmm, ft_strlen(tmm));
	}
	else
	{
		(mi || (f->plus && !mi)) ? p->width-- : 0;
		(!f->plus && !mi && f->space) ? p->width-- : 0;
		mi ? sprint("-", 1) : 0;
		!mi && f->plus ? sprint("+", 1) : 0;
		!mi && !f->plus && f->space ? sprint(" ", 1) : 0;
		ft_putstr_rev(tmm, ft_strlen(tmm));
		print_null_sp(p->width - (int)ft_strlen(tmm), ' ');
	}
}

void	int_all_flags(t_prin *p, int mi, char *tmm)
{
	char	sign;
	int		len;

	len = (int)ft_strlen(tmm);
	p->width--;
	sign = (mi) ? '-' : '+';
	ft_prin_c(sign);
	ft_putstr_rev(tmm, len);
	if (p->width > len)
		print_null_sp(p->width - len, ' ');
}

void	int_plus_zero(t_prin *p, t_flags *f, int mi, char *tmm)
{
	char	a;
	int		len;

	a = (mi) ? '-' : '+';
	len = (int)ft_strlen(tmm);
	p->width--;
	f->space = FALSE;
	f->minus ? f->zero = FALSE : 0;
	if (p->strike == -1 && f->zero)
	{
		ft_prin_c(a);
		print_null_sp(p->width - len, '0');
		ft_putstr_rev(tmm, len);
	}
	else if (p->strike == 0 && f->zero)
	{
		print_null_sp(p->width - len, ' ');
		ft_prin_c(a);
		ft_putstr_rev(tmm, len);
	}
	else if (!f->zero && f->minus)
		int_all_flags(p, mi, tmm);
}

void	int_print_without_flag(t_prin *p, int mi, char *tmm)
{
	int len;

	mi ? p->width-- : 0;
	len = (int)ft_strlen(tmm);
	print_null_sp(p->width - len, ' ');
	mi ? sprint("-", 1) : 0;
	ft_putstr_rev(tmm, len);
}
