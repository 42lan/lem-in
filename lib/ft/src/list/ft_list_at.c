/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:36:35 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/30 12:42:00 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_list_at() function iterates over __list__
** and returns the link at position __pos__.
**
** On success, returns a pointer the chosen link.
** On error, if the list's length is 0 or__pos__ is
** greater than the list's length, returns a
** NULL pointer.
*/

t_list_link	*ft_list_at(t_list *list, unsigned pos)
{
	t_list_link	*link;
	unsigned	i;

	if (list->len == 0 || pos > list->len)
		return (NULL);
	link = list->head;
	if (pos <= list->len / 2 + 1)
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
		i = list->len;
		while (i > pos)
		{
			link = link->prev;
			--i;
		}
	}
	return (link);
}
