/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piskaprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 00:40:38 by masprigg          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	piskaprint(t_prin *p)
{
	char	tmp[2];
	int		len;

	if (p->spec == 0)
	{
		p->form++;
		return ;
	}
	ft_bzero(tmp, 2);
	tim(p);
	(p->spec == 37) ? tmp[0] = '%' : 0;
	len = (int)ft_strlen(tmp);
	if (ft_flag(p->flag, "-"))
	{
		sprint(tmp, len);
		if (p->width > len)
			print_null_sp(p->width - len, ' ');
	}
	else
	{
		if (p->width > len)
			print_null_sp(p->width - len, ' ');
		sprint(tmp, len);
	}
}
