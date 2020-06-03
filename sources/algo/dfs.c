/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:11:29 by abosch            #+#    #+#             */
/*   Updated: 2020/06/03 07:09:44 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "lemin.h"
#include "debug.h"

#include <limits.h>

static unsigned		choose_link(t_farm *f, t_room *room, t_byte type)
{
	unsigned		i;
	unsigned		j;

	i = 0;
	while (i < room->lnk.lst->len && room->lnk.dir[i] != ALLOWED)
		++i;
	j = 0;
	if (type == SIMPLE && i != room->lnk.lst->len)
		return (room->lnk.lst->len);
	while (j < room->lnk.lst->len && room->lnk.arr[j] != room->pre[CUR])
		++j;
	if (i == room->lnk.lst->len || room->lnk.dir[j] != DUPLEX)
	{
		i = 0;
		while (i < room->lnk.lst->len
			&& (f->rooms[room->lnk.arr[i]].flags & F_DEAD
			|| room->cost[CUR] + 1 >= f->rooms[room->lnk.arr[i]].cost[CUR]
			|| room->lnk.dir[i] == BLOCKED))
			++i;
	}
	else if (f->rooms[room->lnk.arr[i]].cost[CUR] <= room->cost[CUR] + 1)
		return (room->lnk.lst->len);
	return (i);
}

static t_room		*traverse(t_farm *f, t_room *start, t_room *room,
						unsigned offset)
{
	t_room			*prev;

	prev = room;
	if (offset == room->lnk.lst->len)
	{
		if (room == start)
			return (NULL);
		else
			room = f->rooms + room->pre[CUR];
	}
	else
	{
		room = f->rooms + room->lnk.arr[offset];
		room->pre[OLD] = room->pre[CUR];
		room->cost[OLD] = room->cost[CUR];
		room->pre[CUR] = prev->index;
		room->cost[CUR] = prev->cost[CUR] + 1;
	}
	return (room);
}

int					dfs(t_farm *f, t_room *start, t_room *target, t_byte type)
{
	unsigned		offset;
	t_room			*room;

	room = start;
	room->pre[CUR] = room->index;
	room->cost[CUR] = 0;
	while (1)
	{
		if (room == target)
		{
			room = f->rooms + room->pre[CUR];
			if (type == FULL)
				continue ;
			else
				break ;
		}
		offset = choose_link(f, room, type);
		if ((room = traverse(f, start, room, offset)) == NULL)
		{
			start->cost[CUR] = 0;
			break ;
		}
	}
	return ((target->pre[CUR] == UINT_MAX) ? FAILURE : SUCCESS);
}
