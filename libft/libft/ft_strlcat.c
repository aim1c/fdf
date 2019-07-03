/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:44:06 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/10 22:11:05 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ls;
	size_t	ld;

	ld = ft_strlen(dst);
	ls = ft_strlen(src);
	if (size <= ld)
		return (ls + size);
	if (ls < size - ld)
	{
		ft_strncpy(dst + ld, src, ls);
		dst += ls + ld;
	}
	else
	{
		ft_strncpy(dst + ld, src, size - ld - 1);
		dst += size - 1;
	}
	*dst = '\0';
	return (ls + ld);
}
