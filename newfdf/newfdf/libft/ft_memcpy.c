/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 00:17:35 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/12 20:17:03 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void			*f;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	f = dst;
	while (n--)
		*s1++ = *s2++;
	return (f);
}
