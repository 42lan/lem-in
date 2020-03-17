/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:36:35 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/13 17:21:32 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_list_at() function iterates over __list__
** and returns the link at position __pos__.
**
** On success, returns a pointer the chosen link.
** On error, if the list's size is 0 or__pos__ is
** greater than the list's size, returns a
** NULL pointer.
*/

t_list_link	*ft_list_at(t_list *list, unsigned pos)
{
	t_list_link	*link;
	unsigned	i;

	if (list->size == 0 || pos > list->size)
		return (NULL);
	link = list->head;
	if (pos <= list->size / 2 + 1)
	{
		i = 0;
		while (i < pos)
		{
			link = link->next;
			++i;
		}
	}
	else
	{
		i = list->size;
		while (i >= pos)
		{
			link = link->prev;
			--i;
		}
	}
	return (link);
}
