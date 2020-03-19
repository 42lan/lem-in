/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:58:49 by abaisago          #+#    #+#             */
/*   Updated: 2020/02/29 16:45:33 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
** Iterates over _list_'s links and applies the
** function _f_ to each link to create “fresh”
** links (using malloc(3)) resulting from the
** successive applications of _f_.
**
** On success, returns the allocated links.
** On error, if an allocation fails, the list's
** size is 0 or _f_ is NULL, returns a NULL pointer.
*/

t_list_link	*ft_list_map(t_list *list, t_list_link *(*f)(t_list_link *elem),
				void (*del)(void*, size_t))
{
	t_list_link	*begin;
	t_list_link *link;
	t_list_link	*map_link;

	if (list->size == 0 || f == NULL)
		return (NULL);
	if ((begin = (*f)(list->head)) == NULL)
		return (NULL);
	link = list->head;
	map_link = begin;
	while (link->next != list->head)
	{
		if ((map_link->next = (*f)(link->next)) == NULL)
		{
			ft_list_del_unsafe(&begin, del);
			return (NULL);
		}
		link = link->next;
		map_link->next->prev = map_link;
		map_link = map_link->next;
	}
	map_link->next = begin;
	begin->prev = map_link;
	return (begin);
}
