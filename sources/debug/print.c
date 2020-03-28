/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 16:10:47 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/28 16:23:19 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "libft.h"

#include "parsing.h"
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

void				hmap_print(t_list *hmap)
{
	int				i;

	i = -1;
	while (++i < HMAP_SIZE)
		if (hmap[i].head != NULL)
		{
			ft_printf("%d: ", i);
			ft_list_print(&hmap[i], dbg_print_room);
		}
}
