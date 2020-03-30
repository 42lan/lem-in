/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:49:02 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/30 12:43:50 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

/*
** The ft_list_init() function allocates
** (with malloc(3)) an empty list and returns it.
**
** On success, returns a pointer to the allocated list.
** On error, return a NULL pointer.
*/

t_list	*ft_list_init(void)
{
	t_list		*list;

	if ((list = malloc(sizeof(*list))) == NULL)
		return (NULL);
	list->head = NULL;
	list->len = 0;
	list->size = 0;
	return (list);
}
