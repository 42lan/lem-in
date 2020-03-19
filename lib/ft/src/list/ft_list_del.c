/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:49:20 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/18 02:18:18 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <string.h>

/*
** The ft_list_del() function takes in __alist__
** a list pointer's adress and frees the memory of 
** each of its links' content using the __del__ 
** function and the link itself using free(3).
**
** *__alist__ is set to NULL.
**
** Returns no value.
*/

void	ft_list_del(t_list **alist, void (*del)(void *, size_t))
{
	t_list		*list;
	t_list_link	*link;
	t_list_link	*next;

	list = *alist;
	if (list->size > 0)
	{
		link = list->head;
		next = link->next;
		while (list->size > 1)
		{
			ft_list_delone(list, link, del);
			link = next;
			next = link->next;
		}
		ft_list_delone(list, link, del);
	}
	list->head = NULL;
	free(list);
	*alist = NULL;
}
