/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 16:10:47 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/26 11:35:52 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "libft.h"

#include "lemin.h"

int		dbg_print_room(void *content, size_t size, unsigned pos, unsigned max)
{
	t_room	*room;
	int		ret;

	room = content;
	ret = ft_printf("[%s %d,%d]", room->name, room->coord.x, room->coord.y);
	if (room->links != NULL)
		ret += ft_printf("(%d) ", room->links->size);
	if (pos == max)
		ret += ft_printf("\n");
	return (ret);
}
