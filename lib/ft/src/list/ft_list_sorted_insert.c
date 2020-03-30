/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sorted_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:03:16 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/30 13:43:58 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_sorted_insert(t_list *list, t_list_link *link, int (*cmp)())
{
	t_list_link	*i;

	if (list->len == 0)
	{
		list->head = link;
		list->len += 1;
	}
	else if (cmp(list->head->prev->content, link->content) <= 0)
		ft_list_push(list, link);
	else
	{
		i = list->head;
		while (i->next != list->head && cmp(i->content, link->content) <= 0)
			i = i->next;
		ft_list_insert(list, i, link);
	}
}
