/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_plus1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 03:57:28 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_only_plus(t_prin *p, int mi, char *tmm)
{
	char	a;
	int		len;

	a = (mi) ? '-' : '+';
	len = (int)ft_strlen(tmm);
	p->width--;
	print_null_sp(p->width - len, ' ');
	ft_prin_c(a);
	ft_putstr_rev(tmm, len);
}

void	int_only_minus(t_prin *p, int mi, char *tmm)
{
	int		len;

	len = (int)ft_strlen(tmm);
	mi ? p->width-- : 0;
	mi ? sprint("-", 1) : 0;
	ft_putstr_rev(tmm, len);
	print_null_sp(p->width - len, ' ');
}

void	int_only_zero(t_prin *p, int mi, char *tmm)
{
	int		len;

	len = (int)ft_strlen(tmm);
	mi ? p->width-- : 0;
	if (p->strike == 0)
	{
		print_null_sp(p->width - len, ' ');
		mi ? sprint("-", 1) : 0;
		ft_putstr_rev(tmm, len);
	}
	else if (p->strike == -1)
	{
		mi ? sprint("-", 1) : 0;
		print_null_sp(p->width - len, '0');
		ft_putstr_rev(tmm, len);
	}
}

void	int_only_space(t_prin *p, int mi, char *tmm)
{
	char	a;
	int		len;

	p->width--;
	len = (int)ft_strlen(tmm);
	a = (mi) ? '-' : ' ';
	print_null_sp(p->width - len, ' ');
	ft_prin_c(a);
	ft_putstr_rev(tmm, len);
}
