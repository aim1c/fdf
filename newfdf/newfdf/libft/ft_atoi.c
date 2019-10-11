/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 23:54:48 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/15 05:23:01 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ABS(value) (value == -1) ? (value = 0) : (value = -1)

int		ft_atoi(const char *str)
{
	long int	nb;
	int			i;
	int			a;

	nb = 0;
	i = 0;
	a = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		(str[i] == '-') ? (a *= -1) : (a = 1);
		i++;
	}
	while (str[i] <= 57 && str[i] >= 48)
	{
		if (nb != (nb * 10) / 10)
			return (ABS(a));
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	nb = (int)(a * nb);
	return (nb);
}
