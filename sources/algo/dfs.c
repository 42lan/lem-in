/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:11:29 by abosch            #+#    #+#             */
/*   Updated: 2020/06/02 18:48:58 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "lemin.h"
#include "debug.h"

#include <limits.h>

static unsigned	choose_link(t_room *room, t_byte type)
{
	unsigned	i;
	unsigned	j;

	(CL_O) ? show_orien(room) : 0;
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
		(CL) ? ft_printf("cas standard\n") : 0;
		i = 0;
		while (i < LINK_SIZE
			&& (ROOMS[LINK_ARR[i]].flags & F_DEAD
			|| room->cost[CUR] + 1 >= ROOMS[LINK_ARR[i]].cost[CUR]
			|| LINK_DIR[i] == BLOCKED))
			++i;
	}
	else if (ROOMS[LINK_ARR[i]].cost[CUR] <= room->cost[CUR] + 1)
		return (LINK_SIZE);
	else if (DEBUGP)
		ft_printf("On arrive sur un path on doit le remonter\n");
	return (i);
}

static t_room	*traverse(t_room *start, t_room *room, unsigned offset)
{
	t_room		*prev;

	prev = room;
	if (offset == LINK_SIZE)
	{
		if (room == start)
			return (NULL);
		else
		{
			room = ROOMS + room->pre[CUR];
			(BACKT) ? ft_printf("{byellow}{fred}we go back{} (PEACE)\n") : 0;
		}
	}
	else
	{
		room = ROOMS + LINK_ARR[offset];
		room->pre[OLD] = room->pre[CUR];
		room->cost[OLD] = room->cost[CUR];
		room->pre[CUR] = prev->index;
		room->cost[CUR] = prev->cost[CUR] + 1;
		(DEBUGP) ? ft_printf("We go deeper\n") : 0;
	}
	return (room);
}

static int		finish(t_room *target)
{
	if (target->pre[CUR] == UINT_MAX)
	{
		if (DEBUGP)
			ft_printf("\nDFS: failure, target :|%s|: not found\n", target->name);
		return (FAILURE);
	}
	else
	{
		if (DEBUGP)
			ft_printf("\nDFS: success, target :|%s|: (%u steps)\n",
				target->name, target->cost[CUR]);
		return (SUCCESS);
	}
}

int		dfs(t_room *start, t_room *target, t_byte type)
{
	t_room		*room;
	unsigned	offset;

	room = start;
	room->pre[CUR] = room->index;
	room->cost[CUR] = 0;
	while (1)
	{
		(DFS) ? ft_printf("\n===| %s || %u |=====< %s\n", room->name, room->cost[CUR], ROOMS[room->pre[CUR]].name) : 0;
		if (room == target)
		{
			room = ROOMS + room->pre[CUR];
			(DFS) ? ft_printf("we go back at end\n=======================\n") : 0;
			if (type == FULL)
				continue ;
			else
				break ;
		}
		offset = choose_link(room, type);
		(DEBUGP) ? ft_printf("offset = %u\n", offset) : 0;
		if ((room = traverse(start, room, offset)) == NULL)
		{
			start->cost[CUR] = 0;
			break ;
		}
		(DFS) ? ft_printf("=================\n") : 0;
	}
	return (finish(target));
}
