/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:26:41 by masprigg          #+#    #+#             */
/*   Updated: 2018/11/29 22:34:38 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (!(mem = (char*)malloc(sizeof(*mem) * (size))))
		return (NULL);
	if (mem == NULL || size == 0)
		return (NULL);
	while (i < size)
	{
		*mem = 0;
		mem++;
		i++;
	}
	mem -= size;
	return (mem);
}
