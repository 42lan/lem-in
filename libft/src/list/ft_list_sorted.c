/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:48:05 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/02 19:53:42 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_sorted(t_list *list, int (*cmp)())
{
	t_list_link *link;

	if (list->size == 0)
		return (1);
	link = list->head;
	while (link->next != list->head)
	{
		if (cmp(link->content, link->next->content) > 0)
			return (0);
		link = link->next;
	}
	return (1);
}
