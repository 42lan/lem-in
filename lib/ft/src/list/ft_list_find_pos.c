/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 19:37:54 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/10 19:50:45 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned	ft_list_find_pos(t_list *list, void *data, int (*cmp)())
{
	t_list_link	*link;
	unsigned	pos;

	if (list->size == 0)
		return (0);
	pos = 1;
	link = list->head;
	while (link->next != list->head)
	{
		if (cmp(link->content, data) == 0)
			return (pos);
		link = link->next;
		++pos;
	}
	if (cmp(link->content, data) == 0)
		return (pos);
	return (0);
}
