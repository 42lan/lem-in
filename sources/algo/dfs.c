/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:11:29 by abosch            #+#    #+#             */
/*   Updated: 2020/06/01 16:22:51 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "lemin.h"
#include "debug.h"

#include <limits.h>
/*
** Destructive backtrace overwrite pre/cost data
*/
void	backtrace_destructive(t_room **curr, t_room *prev)
{
	(DEBUGP) ? ft_printf("{fblack}{bwhite}-------BACK TRACK DESTRUCTIVE AT %s ------{}\n", (*curr)->name) : 0;
	/* * garder dans la memoire d'ou on est venu en faisant backtrace_destructiv() */
	/* * verifier que dans le nodes connectes il n'y a pas de pre[CUR]+cost[CUR+1](nom de node en question + 1) */
	t_room		*room;
	unsigned	offset;
	unsigned	i;

	i = 0;
	room = *curr;
	offset = room->pre[CUR];
	if (room->pre[OLD] != UINT_MAX)
		room->pre[CUR] = room->pre[OLD];
	if (room->cost[OLD] != UINT_MAX)
		room->cost[CUR] = room->cost[OLD];
	prev = room;
	room = ROOMS + LINK_ARR[offset];
	*curr = room;
	while (i < LINK_SIZE && ROOMS + LINK_ARR[i] != prev
			&& (ROOMS[LINK_ARR[i]].flags & F_DEAD
			|| room->cost[CUR] + 1 >= ROOMS[LINK_ARR[i]].cost[CUR]
			|| LINK_DIR[i] == BLOCKED))
		i++;
	if (i == LINK_SIZE || (room->index == ROOMS[LINK_ARR[i]].pre[CUR]
			&& room->cost[CUR] + 1 >= ROOMS[LINK_ARR[i]].cost[CUR]))
	{
		backtrace_passive(&room);
		/* *curr = room; */
	}
	else
	{
		if (*curr != START)
			backtrace_destructive(curr, prev);
		*curr = ROOMS + room->pre[CUR];
		return ;
	}
}
/*
** Update pre/cost data after
*/
void	update_info(t_room **curr, t_room *prev, unsigned offset)
{
	(DEBUGP) ? ft_printf("We go deeper\n") : 0;
	t_room	*room;

	room = *curr;
	room = ROOMS + LINK_ARR[offset];
	room->pre[OLD] = room->pre[CUR];
	room->cost[OLD] = room->cost[CUR];
	room->pre[CUR] = prev->index;
	room->cost[CUR] = prev->cost[CUR] + 1;
	*curr = room;
}

/*
** Passive backtrace do not overwrite pre/cost data
*/
void	backtrace_passive(t_room **room)
{
	(DEBUGP) ? ft_printf("{byellow}{fred}we go back{}\n") : 0;
	*room = ROOMS + (*room)->pre[CUR];
}

t_room	*backtrace_destructive(t_room *room)
{
	unsigned	goback;

	goback = room->pre[CUR];
	if (room->pre[OLD] != UINT_MAX)
		room->pre[CUR] = room->pre[OLD];
	if (room->cost[OLD] != UINT_MAX)
		room->cost[CUR] = room->cost[OLD];
	return (ROOMS + goback);
}

static unsigned	choose_link(t_room *room, t_byte destruc)
{
	unsigned	i;
	unsigned	j;

	i = 0;
	j = 0;
	(DEBUGP) ? show_orien(room) : 0;
	while (i < LINK_SIZE && LINK_DIR[i] != ALLOWED)
		++i;
	(DEBUGP) ? ft_printf("i = %d\n", i) : 0;
	while (j < LINK_SIZE && LINK_ARR[j] != room->pre[CUR])
		++j;
	(DEBUGP) ? ft_printf("j = %d\n", j) : 0;
	if (i == LINK_SIZE || LINK_DIR[j] != DUPLEX)
	{
		(DEBUGP) ? ft_printf("cas standard\n") : 0;
		i = 0;
		while (i < LINK_SIZE && (ROOMS[LINK_ARR[i]].flags & F_DEAD
			|| room->cost[CUR] + 1 >= ROOMS[LINK_ARR[i]].cost[CUR]
			|| LINK_DIR[i] == BLOCKED))
			++i;
		/* ft_printf("while: %u/%u -> %s:%u\n", i + 1, LINK_SIZE, */
		/* 	ROOMS[LINK_ARR[i]].name, ROOMS[LINK_ARR[i]].cost[CUR]); */
	}
	else if (ROOMS[LINK_ARR[i]].cost[CUR] <= room->cost[CUR] + 1 && destruc == 0)
		return (LINK_SIZE);
	else if (DEBUGP) ft_printf("On arrive sur un path on doit le remonter\n");
	return (i);
}

static t_room	*traverse(t_room *start, t_room *room, unsigned offset, t_byte destruc)
{
	t_room		*prev;

	prev = room;
	if (offset == LINK_SIZE)
	{
		if (room == start)
			return (NULL);
		else if (destruc == 1)
			room = backtrace_destructive(room);
		else
			backtrace_passive(&room);
	}
	else
		update_info(&room, prev, offset);
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
		(DEBUGP) ? ft_printf("\n===| %s || %u |=====< %s\n", room->name, room->cost[CUR], ROOMS[room->pre[CUR]].name) : 0;
		if (room == target)
		{
			destruc = 0;
			room = ROOMS + room->pre[CUR];
			(DEBUGP) ? ft_printf("we go back at end\n=======================\n") : 0;
			if (type == FULL)
				continue ;
			else
				break ;
		}
		offset = choose_link(room, destrucc);
		(DEBUGP) ? ft_printf("offset = %u\n", offset) : 0;
		if ((room = traverse(start, room, offset, destruc)) == NULL)
		{
			start->cost[CUR] = 0;
			break ;
		}
		(DEBUGP) ? ft_printf("=================\n") : 0;
	}
	(DEBUGP) ? ft_printf("before finish\n") : 0;
	return (finish(target));
}
