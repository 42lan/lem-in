/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 19:37:54 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/30 13:23:25 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_list_find_pos() function iterates over
** __list__ comparing __data__ to each of its
** links until they are equal (according to
** the __cmp__() function).
**
** On success, returns the position of the found
**             link as an unsigned integer.
** On error, if no link was found, returns 0.
*/

unsigned	ft_list_find_pos(t_list *list, void *data, int (*cmp)())
{
	t_list_link	*link;
	unsigned	pos;

	if (list->len == 0)
		return (0);
	link = list->head;
	pos = 0;
	while (++pos <= list->len)
	{
		if (cmp(link->content, data) == 0)
			return (pos);
		link = link->next;
	}
	return (0);
}
