/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:51:01 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/30 13:50:32 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_list_pop_front() function removes and
** returns the first link of the list __list__.
** The list's size is decremented.
**
** On success, returns the popped link.
** On error, if the list is empty,
** returns a NULL pointer.
*/

t_list_link	*ft_list_pop_front(t_list *list)
{
	t_list_link	*ohead;

	if (list->len == 0)
		return (NULL);
	ohead = list->head;
	if (list->len == 1)
	{
		list->head = NULL;
		list->size = 0;
	}
	else
	{
		list->size -= ohead->content_size;
		list->head = ohead->next;
		list->head->prev = ohead->prev;
		ohead->prev->next = ohead->next;
	}
	--list->len;
	ohead->prev = ohead;
	ohead->next = ohead;
	return (ohead);
}
