/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:10:55 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/30 13:26:40 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_list_find() function iterates over __list__
** comparing each of its links to __data__ until one
** they are equal (according to the __cmp__() function)
**
** On success, returns a pointer to the found link.
** On error, if no link was found, returns NULL.
*/

t_list_link	*ft_list_find(t_list *list, void *data, int (*cmp)())
{
	t_list_link	*link;

	if (list->len == 0)
		return (NULL);
	link = list->head;
	while (link->next != list->head)
	{
		if (cmp(link->content, data) == 0)
			return (link);
		link = link->next;
	}
	if (cmp(link->content, data) == 0)
		return (link);
	return (NULL);
}
