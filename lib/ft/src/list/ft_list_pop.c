/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:42:14 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/30 13:50:17 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_list_pop_back() function removes and
** returns the last link of the list __list__.
** The list's size is decremented.
**
** On success, returns the popped link.
** On error, if the list is empty,
** returns a NULL pointer.
*/

t_list_link	*ft_list_pop(t_list *list)
{
	t_list_link	*tail;

	if (list->len == 0)
		return (NULL);
	tail = list->head->prev;
	if (list->len == 1)
	{
		list->head = NULL;
		list->size = 0;
	}
	else
	{
		list->size -= tail->content_size;
		tail->next->prev = tail->prev;
		tail->prev->next = tail->next;
	}
	--list->len;
	tail->prev = tail;
	tail->next = tail;
	return (tail);
}
