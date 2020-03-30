/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:24:55 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/30 13:40:24 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_list_push() function adds
** __link__ to the end of t_list __list__.
**
** If __link__ is NULL, does nothing.
**
** Returns no value.
*/

void	ft_list_push(t_list *list, t_list_link *link)
{
	t_list_link	*head;

	if (link == NULL)
		return ;
	if (list->len == 0)
		list->head = link;
	else
	{
		head = list->head;
		head->prev->next = link;
		link->prev = head->prev;
		head->prev = link;
		link->next = head;
	}
	list->len += 1;
	list->size += link->content_size;
}
