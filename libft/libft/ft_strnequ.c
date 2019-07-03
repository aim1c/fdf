/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 19:20:44 by masprigg          #+#    #+#             */
/*   Updated: 2018/11/29 22:01:29 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL && s2 == NULL)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*s1 && *s2 && n && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (n == 0)
		return (1);
	return (0);
}
