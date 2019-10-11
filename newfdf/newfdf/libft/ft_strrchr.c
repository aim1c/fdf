/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 22:21:12 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/10 23:49:53 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*f;
	char	*r;

	f = (char*)s;
	r = NULL;
	while (*f)
	{
		if (*f == (char)c)
			r = f;
		f++;
	}
	if (!c)
		return (f);
	return ((char*)r);
}
