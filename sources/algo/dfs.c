/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:11:29 by abosch            #+#    #+#             */
/*   Updated: 2020/06/01 19:25:19 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "lemin.h"
#include "debug.h"

#include <limits.h>
/*
** Update pre/cost data after
*/
t_room	*update_info(t_room *room, t_room *prev, unsigned offset)
{
	(DEBUGP) ? ft_printf("We go deeper\n") : 0;
	room = ROOMS + LINK_ARR[offset];
	room->pre[OLD] = room->pre[CUR];
	room->cost[OLD] = room->cost[CUR];
	room->pre[CUR] = prev->index;
	room->cost[CUR] = prev->cost[CUR] + 1;
	return (room);
}

/*
** Passive backtrace do not overwrite pre/cost data
*/
t_room	*backtrace_passive(t_room *room)
{
	(BACKT) ? ft_printf("{byellow}{fred}we go back{} (PEACE)\n") : 0;
	return (ROOMS + room->pre[CUR]);
}

t_room	*backtrace_destructive(t_room *room)
{
	unsigned	goback;

	(BACKT) ? ft_printf("{bblue}{fred}we go back{} (BOOM)\n") : 0;
	goback = room->pre[CUR];
	room->pre[CUR] = room->pre[OLD];
	room->pre[OLD] = goback;
	room->cost[CUR] = room->cost[OLD];
	return (ROOMS + goback);
}

static unsigned	choose_link(t_room *room)
{
	unsigned	i;
	unsigned	j;

	i = 0;
	j = 0;
	(CL_O) ? show_orien(room) : 0;
	while (i < LINK_SIZE && LINK_DIR[i] != ALLOWED)
		++i;
	(CL) ? ft_printf("i = %d\n", i) : 0;
	while (j < LINK_SIZE && LINK_ARR[j] != room->pre[CUR])
		++j;
	(CL) ? ft_printf("j = %d\n", j) : 0;
	if (i == LINK_SIZE || LINK_DIR[j] != DUPLEX)
	{
		(CL) ? ft_printf("cas standard\n") : 0;
		i = 0;
		while (i < LINK_SIZE && (ROOMS[LINK_ARR[i]].flags & F_DEAD
			|| room->cost[CUR] + 1 >= ROOMS[LINK_ARR[i]].cost[CUR]
			|| LINK_DIR[i] == BLOCKED
			|| (room->index == ROOMS[LINK_ARR[i]].pre[OLD])))
			++i;
		/* ft_printf("while: %u/%u -> %s:%u\n", i + 1, LINK_SIZE, */
		/* 	ROOMS[LINK_ARR[i]].name, ROOMS[LINK_ARR[i]].cost[CUR]); */
	}
	else if (ROOMS[LINK_ARR[i]].cost[CUR] <= room->cost[CUR] + 1)
		return (LINK_SIZE);
	else if (CL) ft_printf("On arrive sur un path on doit le remonter\n");
	return (i);
}

static t_room	*traverse(t_room *start, t_room *room, unsigned offset, t_byte *destruc)
{
	unsigned	i;
	t_room		*prev;

	prev = room;
	if (offset == LINK_SIZE)
	{
		if (room == start)
			return (NULL);
		i = -1;
		while (++i < LINK_SIZE)
		{
			if (room->index == ROOMS[LINK_ARR[i]].pre[OLD])
			{
				ft_printf("****** %s, %s\n", room->name, ROOMS[LINK_ARR[i]].name);
				continue ;
			}
			if (room->index == ROOMS[LINK_ARR[i]].pre[CUR]
					&& room->cost[CUR] + 1 == ROOMS[LINK_ARR[i]].cost[CUR])
				break ;
		}
		if (i != LINK_SIZE)
			*destruc = 1;
		else
			*destruc = 0;
		if (*destruc == 1 && room->pre[OLD] != UINT_MAX)
			room = backtrace_destructive(room);
		else
			room = backtrace_passive(room);
	}
	else
		room = update_info(&room, prev, offset);
	return (room);
}

static int		finish(t_room *target)
{
	if (target->pre[CUR] == UINT_MAX)
	{
		(DEBUGP) ? ft_printf("\nDFS: failure, target :|%s|: not found\n", target->name) : 0;
		return (FAILURE);
	}
	else
	{
		(DEBUGP) ? ft_printf("\nDFS: success, target :|%s|: (%u steps)\n", target->name, target->cost[CUR]) : 0;
		return (SUCCESS);
	}
}

int		dfs(t_room *start, t_room *target, t_byte type)
{
	t_room		*room;
	unsigned	offset;
	t_byte		destruc;

	room = start;
	room->pre[CUR] = room->index;
	room->cost[CUR] = 0;
	destruc = 0;
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
		offset = choose_link(room);
		(DFS) ? ft_printf("offset = %u\n", offset) : 0;
		if ((room = traverse(start, room, offset, &destruc)) == NULL)
		{
			start->cost[CUR] = 0;
			break ;
		}
		(DFS) ? ft_printf("=================\n") : 0;
	}
	return (finish(target));
}
