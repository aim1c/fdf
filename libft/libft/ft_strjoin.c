/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 20:02:29 by masprigg          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	char	*venom;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	venom = (char*)malloc(sizeof(*venom) * (l + 1));
	if (venom == NULL)
		return (NULL);
	while (*s1 && s1 != NULL)
	{
		*venom = *s1;
		venom++;
		s1++;
	}
	while (*s2 && s2 != NULL)
	{
		*venom = *s2;
		venom++;
		s2++;
	}
	*venom = '\0';
	venom -= l;
	return (venom);
}
