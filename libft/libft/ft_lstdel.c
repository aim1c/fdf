/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masprigg <masprigg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:34:21 by masprigg          #+#    #+#             */
/*   Updated: 2019/05/29 00:58:10 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (*alst == NULL || alst == NULL || del == NULL)
		return ;
	tmp = (*alst)->next;
	del((*alst)->content, (*alst)->content_size);
	while (tmp != NULL)
	{
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = tmp->next;
	}
	free(*alst);
	*alst = NULL;
}
