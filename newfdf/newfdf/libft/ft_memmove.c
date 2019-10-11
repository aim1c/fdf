/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 00:52:59 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/15 05:07:10 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*s1;
	const unsigned char	*s2;

	s1 = (unsigned char*)dst;
	s2 = (const unsigned char*)src;
	if (src > dst)
	{
		ft_memcpy(dst, src, len);
	}
	else if (src < dst)
	{
		while (len--)
			s1[len] = s2[len];
	}
	return (s1);
}
