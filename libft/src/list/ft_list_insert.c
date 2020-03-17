/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:25:41 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/05 20:05:02 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_insert(t_list *list, t_list_link *dst, t_list_link *src)
{
	src->prev = dst->prev;
	src->next = dst;
	src->prev->next = src;
	dst->prev = src;
	if (dst == list->head)
		list->head = src;
	list->size += 1;
}
