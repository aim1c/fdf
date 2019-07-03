/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:25:30 by masprigg          #+#    #+#             */
/*   Updated: 2018/12/13 21:08:53 by masprigg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*wow;

	if (lst == NULL || f == NULL)
		return ;
	wow = lst;
	while (wow->next)
	{
		f(wow);
		wow = wow->next;
	}
	f(wow);
}
