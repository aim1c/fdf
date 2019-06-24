/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 23:59:07 by masprigg          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h1;
	char	*h2;
	char	*n1;
	char	*n2;
	size_t	a;

	a = 0;
	h1 = (char*)haystack;
	h2 = (char*)haystack;
	n1 = (char*)needle;
	n2 = (char*)needle;
	if (*needle == '\0' || haystack == needle)
		return (h1);
	while (*h1)
	{
		while (*n2 && *h2++ == *n2++)
			a++;
		if (a == ft_strlen(needle))
			return (h1);
		h1++;
		h2 = h1;
		n2 = n1;
		a = 0;
	}
	return (NULL);
}
