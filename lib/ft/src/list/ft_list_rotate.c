/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:11:56 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/18 15:05:57 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_list_rotate() function moves __list__'s
** head pointer __rot__ positions, effectively
** rotating the list.
**
** Returns no value.
*/

void	ft_list_rotate(t_list *list, int rot)
{
	if (list->size == 0)
		return ;
	if (rot < 0)
		rot = (list->size + rot) % list->size;
	else
		rot = rot % list->size;
	list->head = ft_list_at(list, (unsigned)rot);
}
