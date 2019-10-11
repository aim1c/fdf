/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 22:25:46 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/15 05:54:03 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_pfront(t_list **f, void const *con, size_t c_size)
{
	t_list	*b;

	b = ft_lstnew(con, c_size);
	b->next = *f;
	*f = b;
}
