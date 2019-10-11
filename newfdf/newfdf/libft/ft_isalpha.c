/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 00:21:42 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/12 20:15:17 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1024);
	else
		return (0);
}

static int	ft_islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1024);
	else
		return (0);
}

int			ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
