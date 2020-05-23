/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:19:41 by abaisago          #+#    #+#             */
/*   Updated: 2020/05/11 15:35:03 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_list *list, void (*del)(void *, size_t))
{
	t_list_link	*link;
	t_list_link	*next;

	if (list->len == 0)
		return ;
	link = list->head;
	next = link->next;
	while (list->len > 1)
	{
		ft_list_delone(list, link, del);
		link = next;
		next = link->next;
	}
	ft_list_delone(list, link, del);
	list->head = NULL;
}
