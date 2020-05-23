/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:05:51 by abaisago          #+#    #+#             */
/*   Updated: 2020/05/11 15:36:19 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_list_remove() function removes the link
** __link__ from the list __list__ using the __del__
** function.
**
** Returns no value.
*/

void	ft_list_remove(t_list *list, t_list_link *link,
			void (*del)(void *, size_t))
{
	if (list->len == 0)
		return ;
	if (link == list->head)
		list->head = link->next;
	ft_list_delone(list, link, del);
	if (list->len == 0)
		list->head = NULL;
}
