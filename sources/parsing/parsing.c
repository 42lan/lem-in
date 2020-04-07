/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 09:32:10 by amalsago          #+#    #+#             */
/*   Updated: 2020/04/07 14:42:58 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

#include "debug.h"
#include "lemin.h"
#include "predicates.h"
#include "tools.h"

#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void		link_to_array(t_room *room)
{
	unsigned	j;

	if ((room->link.arr = (unsigned*)ft_list_to_arr(room->link.list,
					sizeof (unsigned), NULL)) == NULL)
		ft_printerr("lem-in: links_to_array(arr malloc): %s\n",
				strerror(errno));
	if (room->link.list->len != 0)
	{
		if ((room->link.dir =
					(t_byte*)malloc(room->link.list->len)) == NULL)
			ft_printerr("lem-in: links_to_array(dir malloc): %s\n",
					strerror(errno));
		j = -1;
		while (++j < room->link.list->len)
			room->link.dir[j] = BOTH;
	}
}

void		preparation(t_room *rooms, unsigned size)
{
	unsigned	i;

	i = -1;
	while (++i < size)
	{
		link_to_array(&rooms[i]);
		rooms[i].cost[0] = -1;
		rooms[i].cost[1] = -1;
		rooms[i].pre[0] = -1;
		rooms[i].pre[1] = -1;
		rooms[i].ant_id = -1;
	}
}

int			parse_input(t_farm *farm, t_list *hmap)
{
	t_list	*room_list; //TODO Needs to be freed

	farm->ants_total = get_ants();
	farm->ants_start = farm->ants_total;
	farm->ants_end = 0;
	room_list = get_room_list(farm, hmap);
	// TODO: Needs to be freed
	if ((farm->rooms = (t_room*)ft_list_to_arr(room_list,
					sizeof (t_room), NULL)) == NULL)
		ft_printerr("lem-in: get_rooms(list_to_arr): %s\n", strerror(errno));
	farm->size = room_list->len;
	preparation(farm->rooms, farm->size);
	dbg_farm_print(farm);
	return (SUCCESS);
}
