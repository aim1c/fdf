/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:58:26 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/10 21:24:50 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*f;
	int		l;

	f = s1;
	while (*s1)
		s1++;
	l = ft_strlen(s2);
	s1 = ft_memcpy(s1, s2, l + 1);
	return (f);
}
