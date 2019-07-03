/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 00:38:20 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/12 23:22:54 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hays, const char *nee, size_t len)
{
	char	*h1;
	char	*h2;
	char	*n2;
	size_t	a;
	size_t	l;

	a = 0;
	l = len;
	h1 = (char*)hays;
	h2 = (char*)hays;
	n2 = (char*)nee;
	if (*nee == '\0' || hays == nee)
		return (h1);
	while (*h1 && l--)
	{
		while (*n2 && h2 < hays + len && *h2++ == *n2++)
			a++;
		if (a == ft_strlen(nee))
			return (h1);
		h1++;
		h2 = h1;
		n2 = (char*)nee;
		a = 0;
	}
	return (NULL);
}
