/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:13:48 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/30 16:11:26 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds _link_ to the beginning of t_list _list_.
**
** If _link_ is NULL, simply return while
** doing nothing.
**
** Does not return anything.
*/

void	ft_list_push_front(t_list *list, t_list_link *link)
{
	t_list_link	*head;

	if (link == NULL)
		return ;
	if (list->len == 0)
		list->head = link;
	else
	{
		head = list->head;
		ft_printf("test: %p\n", head);
		link->prev = head->prev;
		link->next = head;
		head->prev->next = link;
		head->prev = link;
		list->head = link;
	}
	list->len += 1;
	list->size += link->content_size;
}
