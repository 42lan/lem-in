/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:34:54 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/30 13:31:49 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

/*
** The ft_list_new() function allocates a list
** (with malloc(3)) and populates with the link(s)
** in __link__, the list's size is calculated by
** looping over the links.
**
** On success, returns a pointer to the allocated list.
** On error, return a NULL pointer.
*/

t_list	*ft_list_new(t_list_link *link)
{
	t_list		*list;

	if ((list = malloc(sizeof(*list))) == NULL)
		return (NULL);
	list->head = link;
	if (link == NULL)
	{
		list->len = 0;
		list->size = 0;
	}
	else
	{
		list->len = 1;
		list->size += link->content_size;
		while (link->next != list->head)
		{
			link = link->next;
			++list->len;
			list->size += link->content_size;
		}
	}
	return (list);
}
