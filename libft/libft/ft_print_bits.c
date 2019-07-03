/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:11:19 by masprigg          #+#    #+#             */
/*   Updated: 2019/02/05 16:07:03 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	int	oct;
	int	count;

	oct = octet;
	count = 0;
	while (count < 8)
	{
		if (oct & 128)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		oct = oct << 1;
		count++;
	}
}
