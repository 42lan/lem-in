/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:25:41 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/30 12:47:18 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_list_insert function inserts a link __src__
** in place of the link __dst__ of the list __list__.
**
** Returns no value.
*/

void	ft_list_insert(t_list *list, t_list_link *dst, t_list_link *src)
{
	src->prev = dst->prev;
	src->next = dst;
	src->prev->next = src;
	dst->prev = src;
	if (dst == list->head)
		list->head = src;
	list->len += 1;
	list->size += src->content_size;
}
