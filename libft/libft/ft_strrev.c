/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 03:09:54 by masprigg          #+#    #+#             */
/*   Updated: 2019/02/18 03:18:05 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *p)
{
	char	*s;
	char	*r;
	char	temp;

	s = p;
	r = p + ft_strlen(p) - 1;
	while (p < r)
	{
		temp = *p;
		*p = *r;
		*r = temp;
		p++;
		r--;
	}
	return (s);
}
