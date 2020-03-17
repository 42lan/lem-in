/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_link_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:04:36 by abaisago          #+#    #+#             */
/*   Updated: 2020/02/29 19:25:45 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** The ft_list_link_new() functions allocates
** (with malloc(3)) and returns a “fresh” link.
** The link's member variables are initialized
** by allocating __content_size__ memory and
** copying the __content__ into the link.
**
** If the argument __content__ is NULL, thelink's
** member variables content and content_size
** are set to NULL and 0 respectively.
** The member variables next and prev are initialized to NULL.
**
** On success, return the allocated link.
** On error, If an allocation fails,
** returns a NULL pointer.
*/

t_list_link	*ft_list_link_new(void const *content, size_t content_size)
{
	t_list_link	*new;

	if ((new = malloc(sizeof(*new))) == NULL)
		return (NULL);
	if (content != NULL)
	{
		if ((new->content = malloc(content_size)) == NULL)
		{
			free(new);
			new = NULL;
			return (NULL);
		}
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->prev = new;
	new->next = new;
	return (new);
}
