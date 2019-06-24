/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ccprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 03:12:36 by masprigg          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		cprint(t_prin *p)
{
	int	a;

	if (p->lenght[0] == 'l' || p->lenght[0] == 'w' || p->spec == 'C')
		a = va_arg(p->ap, int);
	else
		a = (char)va_arg(p->ap, int);
	tim(p);
	if (ft_flag(p->flag, "-"))
	{
		ft_prin_c(a);
		print_null_sp(p->width - 1, ' ');
	}
	else
	{
		print_null_sp(p->width - 1, ' ');
		ft_prin_c(a);
	}
}
