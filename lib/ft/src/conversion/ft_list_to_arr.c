/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 15:57:38 by abaisago          #+#    #+#             */
/*   Updated: 2020/05/11 15:34:22 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

/*
** The ft_list_to_arr() function will parse and
** allocate for an array of pointers to each element
** of the list (list).
**
** f(void*, size_t, unsigned, unsigned)
** __term_size__ is the size in bytes that the null
** terminating element should be.
**
** On success, returns a pointer to the array.
** On error, returns NULL.
*/

void	*ft_list_to_arr(t_list *list, unsigned term_size, void (*f)())
{
	void		*tab;
	size_t		acc;
	t_list_link	*link;
	unsigned	i;

	if ((tab = malloc(list->size + term_size)) == NULL)
		return (NULL);
	ft_bzero(tab + list->size, term_size);
	link = list->head;
	acc = 0;
	i = -1;
	while (++i < list->len)
	{
		ft_memcpy(tab + acc, link->content, link->content_size);
		if (f != NULL)
			f(tab + acc, link->content_size, i + 1, list->size);
		acc += link->content_size;
		link = link->next;
	}
	return (tab);
}
