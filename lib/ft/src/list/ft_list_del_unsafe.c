/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del_unsafe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:49:20 by abaisago          #+#    #+#             */
/*   Updated: 2020/02/29 16:36:47 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
** The ft_list_link_del_unsafe() takes in _alink_,
** a link pointer's address and frees the memory of
** every link in the chain using the _del_ and
** free(3) functions, setting their pointers to NULL.
** The pointer at *_alink_ is also set to NULL.
**
** Returns no value.
*/

void	ft_list_del_unsafe(t_list_link **alink,
			void (*del)(void *, size_t))
{
	t_list_link	*head;
	t_list_link	*link;
	t_list_link	*next;

	head = *alink;
	link = head;
	next = link->next;
	while (next != head)
	{
		ft_list_delone_unsafe(&link, del);
		link = next;
		next = link->next;
	}
	ft_list_delone_unsafe(&link, del);
	*alink = NULL;
}
