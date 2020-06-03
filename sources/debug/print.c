/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 16:10:47 by abaisago          #+#    #+#             */
/*   Updated: 2020/06/03 04:55:48 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "libft.h"

#include "lemin.h"
#include "parsing.h"

int				dbg_print_room(void *content, size_t size, unsigned pos,
					unsigned max)
{
	int			ret;
	t_room		*room;

	room = content;
	ret = ft_printf("=%u: [%-5s %d,%d]", room->index, room->name,
		room->coord.x, room->coord.y);
	ret += ft_printf("(%d) \n", room->link.list->size);
	if (pos == max)
		ret += ft_printf("\n");
	return (ret);
}

void			dbg_hmap_print(t_list *hmap)
{
	int			i;

	i = -1;
	while (++i < HMAP_SIZE)
		if (hmap[i].head != NULL)
		{
			ft_printf("%4d: ", i);
			ft_list_print(&hmap[i], dbg_print_room);
		}
}

static char		*room_type(t_byte flags)
{
	if (flags & F_DEAD)
		return ("DEAD-");
	else if (flags & F_START)
		return ("START");
	else if (flags & F_END)
		return ("END");
	return ("");
}

void			dbg_farm_print(t_farm *farm)
{
	unsigned	i;
	unsigned	j;
	t_room		*room;

	ft_printf("Total number of ants: %d\n", farm->ants_total);
	i = -1;
	while (++i < farm->size)
	{
		room = &farm->rooms[i];
		ft_printf("%04u: #%05u [%-5s %04d,%04d %5s] (%u)",
			hmap_index(room->name), room->index, room->name, room->coord.x,
			room->coord.y, room_type(room->flags), room->link.list->len);
		j = -1;
		while (++j < room->link.list->len)
			ft_printf(room->link.arr[j + 1] ? " %s >" : " %s",
				farm->rooms[room->link.arr[j]].name);
		ft_putchar('\n');
	}
}

void			print_paths_from(t_room *start)
{
	unsigned	i;
	unsigned	begin;
	t_room		*room;

	begin = -1;
	while (++begin < start->LINK_LEN)
		if (start->link.dir[begin] == BLOCKED)
		{
			i = -1;
			room = ROOMS + start->link.arr[begin];
			ft_printf("%s -> %s ", start->name, room->name);
			while (++i < room->LINK_LEN)
				if (LINK_DIR[i] == BLOCKED)
				{
					room = ROOMS + LINK_ARR[i];
					ft_printf("-> %s ", room->name);
					i = -1;
				}
			ft_putchar('\n');
		}
}
