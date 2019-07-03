/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:39:37 by masprigg          #+#    #+#             */
/*   Updated: 2019/02/10 05:03:09 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*a;
	int				i;

	addr += size - 1;
	i = 0;
	while (i < 16 && size)
	{
		a = (unsigned char *)addr;
		(*a / 16) > 9 ? ft_putchar('A' + (*a / 16) - 10)
				: ft_putchar('0' + (*a / 16));
		(*a % 16) > 9 ? ft_putchar('A' + (*a % 16) - 10)
				: ft_putchar('0' + (*a % 16));
		if (i % 2)
			write(1, " ", 1);
		addr--;
		i++;
		size--;
	}
	write(1, "\n", 1);
}
