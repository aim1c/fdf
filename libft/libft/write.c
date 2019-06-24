/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:45:46 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:09 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_rev(char *tmp, int i)
{
	int len;

	len = i - 1;
	while (i > 0)
	{
		ft_prin_c(tmp[len]);
		i--;
		len--;
	}
}

void	print_null_sp(int widh, char a)
{
	while (widh > 0)
	{
		ft_prin_c(a);
		widh--;
	}
}
