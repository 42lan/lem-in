/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:05:46 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/01 08:58:37 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
** The ft_list_iter() function iterates over __list__
** and applies the __f__ function to each link.
**
** Returns no value.
*/

void	ft_list_iter(t_list *list, void (*f)(t_list_link *elem))
{
	t_list_link	*link;

	link = list->head;
	while (link->next != list->head)
	{
		(*f)(link);
		link = link->next;
	}
	(*f)(link);
}
