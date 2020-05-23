/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_delone_unsafe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:15:33 by abaisago          #+#    #+#             */
/*   Updated: 2020/05/10 21:21:25 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

/*
** The ft_list_delone_unsafe() function takes in
** _alink_, a link’s pointer address and frees the
** memory of that link’s content using the _del_
** function, then frees the link itself using free(3)
** while setting the pointer at *_alink_ to NULL.
** The pointers of the previous and next links are
** also set accordingly.
**
** Does not return anything.
*/

void	ft_list_delone_unsafe(t_list_link **alink,
			void (*del)(void*, size_t))
{
	t_list_link	*link;

	link = *alink;
	(*del)(link->content, link->content_size);
	link->prev->next = link->next;
	link->next->prev = link->prev;
	link->prev = NULL;
	link->next = NULL;
	free(link->content);
	link->content = NULL;
	link->content_size = 0;
	free(link);
	*alink = NULL;
}
