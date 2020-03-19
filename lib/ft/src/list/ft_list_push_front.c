/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:13:48 by abaisago          #+#    #+#             */
/*   Updated: 2020/02/29 19:30:41 by abaisago         ###   ########.fr       */
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
	if (list->size == 0)
		list->head = link;
	else
	{
		head = list->head;
		link->prev = head->prev;
		link->next = head;
		head->prev->next = link;
		head->prev = link;
		list->head = link;
	}
	list->size += 1;
}
