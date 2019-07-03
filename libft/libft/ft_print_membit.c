/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_membit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:16:07 by masprigg          #+#    #+#             */
/*   Updated: 2019/02/14 02:26:03 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_membit(void *addr, unsigned int size)
{
	unsigned char	*a;
	int				i;

	addr += size - 1;
	while (size)
	{
		a = (unsigned char *)addr;
		i = 0;
		while (i < 8)
		{
			if ((*a >> (7 - i)) & 1)
				ft_putchar('1');
			else
				ft_putchar('0');
			i++;
		}
		write(1, " ", 1);
		addr -= sizeof(char);
		size--;
	}
	write(1, "\n", 1);
}

char		*ft_get_membit(void *addr, unsigned int size)
{
	unsigned char	*a;
	char			*mem;
	char			*start;
	int				i;

	addr += size - 1;
	mem = (char *)malloc(sizeof(char) * ((size * 8) + 1));
	start = mem;
	while (size--)
	{
		a = (unsigned char *)addr;
		i = 0;
		while (i < 8)
		{
			if ((*a >> (7 - i)) & 1)
				*mem = '1';
			else
				*mem = '0';
			i++;
			mem++;
		}
		addr -= sizeof(char);
	}
	*mem = '\0';
	return (start);
}
