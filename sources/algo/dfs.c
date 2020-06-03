/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:11:29 by abosch            #+#    #+#             */
/*   Updated: 2020/06/03 03:57:48 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "lemin.h"
#include "debug.h"

#include <limits.h>

static unsigned		choose_link(t_room *room, t_byte type)
{
	unsigned		i;
	unsigned		j;

	i = 0;
	while (i < LINK_SIZE && LINK_DIR[i] != ALLOWED)
		++i;
	j = 0;
	if (type == SIMPLE && i != LINK_SIZE)
		return (LINK_SIZE);
	while (j < LINK_SIZE && LINK_ARR[j] != room->pre[CUR])
		++j;
	if (i == LINK_SIZE || LINK_DIR[j] != DUPLEX)
	{
		i = 0;
		while (i < LINK_SIZE
			&& (ROOMS[LINK_ARR[i]].flags & F_DEAD
			|| room->cost[CUR] + 1 >= ROOMS[LINK_ARR[i]].cost[CUR]
			|| LINK_DIR[i] == BLOCKED))
			++i;
	}
	else if (ROOMS[LINK_ARR[i]].cost[CUR] <= room->cost[CUR] + 1)
		return (LINK_SIZE);
	return (i);
}

static t_room		*traverse(t_room *start, t_room *room, unsigned offset)
{
	t_room			*prev;

	prev = room;
	if (offset == LINK_SIZE)
	{
		if (room == start)
			return (NULL);
		else
			room = ROOMS + room->pre[CUR];
	}
	else
	{
		room = ROOMS + LINK_ARR[offset];
		room->pre[OLD] = room->pre[CUR];
		room->cost[OLD] = room->cost[CUR];
		room->pre[CUR] = prev->index;
		room->cost[CUR] = prev->cost[CUR] + 1;
	}
	return (room);
}

int					dfs(t_room *start, t_room *target, t_byte type)
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
			room = ROOMS + room->pre[CUR];
			if (type == FULL)
				continue ;
			else
				break ;
		}
		offset = choose_link(room, type);
		if ((room = traverse(start, room, offset)) == NULL)
		{
			start->cost[CUR] = 0;
			break ;
		}
	}
	return ((target->pre[CUR] == UINT_MAX) ? FAILURE : SUCCESS);
}
