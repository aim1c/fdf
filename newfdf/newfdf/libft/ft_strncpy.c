/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 23:28:43 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/15 03:53:31 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int		l;
	char	*a;

	l = -1;
	a = dst;
	if (ft_strlen(src) < len)
	{
		l = ft_strlen(src);
	}
	if (l == -1)
		dst = ft_memcpy(dst, src, len);
	else
	{
		dst = ft_memcpy(dst, src, l);
		len -= l;
		dst += l;
		while (len--)
			*(dst++) = '\0';
	}
	return (a);
}
