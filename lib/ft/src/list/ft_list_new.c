/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:34:54 by abaisago          #+#    #+#             */
/*   Updated: 2020/02/29 20:34:03 by abaisago         ###   ########.fr       */
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
		list->size = 0;
	else
	{
		list->size = 1;
		while (link->next != list->head)
		{
			link = link->next;
			++list->size;
		}
	}
	return (list);
}
