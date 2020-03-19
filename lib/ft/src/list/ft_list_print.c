/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:05:22 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/01 08:58:17 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_list_print() function iterates over__list__
** and applies the __print__ function to each link.
**
** Returns the accumulated integer returned by all
** the calls to __print__.
*/

int		ft_list_print(t_list *list, int (*print)(void *, size_t, unsigned))
{
	unsigned	pos;
	int			ret;
	t_list_link	*link;

	if (list->size == 0)
		return (0);
	pos = 1;
	ret = 0;
	link = list->head;
	while (link->next != list->head)
	{
		ret += ft_list_printone(link, pos, print);
		link = link->next;
		++pos;
	}
	ret += ft_list_printone(link, pos, print);
	return (ret);
}
