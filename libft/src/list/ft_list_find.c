/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:10:55 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/01 20:06:50 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_link	*ft_list_find(t_list *list, void *data, int (*cmp)())
{
	t_list_link	*link;

	if (list->size == 0)
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
