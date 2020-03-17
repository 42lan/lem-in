/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:15:33 by abaisago          #+#    #+#             */
/*   Updated: 2020/02/29 17:48:56 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <string.h>
#include <stdlib.h>

/*
** The ft_list_delone() function takes in _link_,
** frees the link’s content using the _del_ function
** and frees the link itself using free(3).
**
** The pointers of the previous and next links are
** also set accordingly
** __list__->size is decremented.
**
** Return no value.
*/

void	ft_list_delone(t_list *list, t_list_link *link,
			void (*del)(void*, size_t))
{
	(*del)(link->content, link->content_size);
	link->prev->next = link->next;
	link->next->prev = link->prev;
	link->prev = NULL;
	link->next = NULL;
	link->content = 0;
	link->content_size = 0;
	free(link);
	list->size -= 1;
}
