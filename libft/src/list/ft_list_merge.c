/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:19:34 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/01 14:45:29 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_list_merge() function merges the list
** pointed to by *__aright__ and list __left__ into
** __left__. __left__'s size is set accordingly.
**
** Returns no value.
*/

void					ft_list_merge(t_list *left, t_list **aright)
{
	t_list	*right;
	
	right = *aright;
	if (left->size > 0 && right->size > 0)
	{
		left->head->prev->next = right->head;
		right->head->prev->next = left->head;
		left->size += right->size;
	}
	else if (right->size > 0)
	{
		left->head = right->head;
		left->size = right->size;
	}
}
