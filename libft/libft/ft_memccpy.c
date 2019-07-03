/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 00:27:27 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/14 20:54:26 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (!n)
		return (NULL);
	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	while (*s2 != (unsigned char)c && n--)
		*s1++ = *s2++;
	if (*s2 == (unsigned char)c && n)
	{
		*s1++ = *s2++;
		return ((void*)s1);
	}
	return (NULL);
}
