/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 15:57:38 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/26 19:14:37 by abaisago         ###   ########.fr       */
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
**
** On success, returns a pointer to the array.
** On error, returns NULL.
*/

void	**ft_list_to_arr(t_list *list, void (*f)())
{
	void		**tab;
	t_list_link	*link;
	unsigned	i;

	if ((tab = malloc(sizeof *tab * list->size)) == NULL)
		return (NULL);
	link = list->head;
	i = -1;
	while(++i < list->size)
	{
		tab[i] = link->content;
		if (f != NULL)
			f(tab[i], link->content_size, i + 1, list->size);
		link = link->next;
	}
	return (tab);
}
