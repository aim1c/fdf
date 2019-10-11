/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:47:04 by masprigg          #+#    #+#             */
/*   Updated: 2018/11/29 22:34:07 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	if ((size_t)(-1) == size)
		return (NULL);
	if (!(new = ft_memalloc(size + 1)))
		return (NULL);
	new[size] = '\0';
	return (new);
}
