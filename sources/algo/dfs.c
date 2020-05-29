/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:11:29 by abosch            #+#    #+#             */
/*   Updated: 2020/05/27 17:11:38 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "lemin.h"
#include "debug.h"

#include <limits.h>

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
	(DEBUGP) ? ft_printf("we go back\n") : 0;
	*room = ROOMS + (*room)->pre[CUR];
}

/*
** Destructive backtrace overwrite pre/cost data
*/
void	backtrace_destructive(t_room **curr, t_room *prev)
{
	/* * garder dans la memoire d'ou on est venu en faisant backtrace_destructiv() */
	/* * verifier que dans le nodes connectes il n'y a pas de pre[CUR]+cost[CUR+1](nom de node en question + 1) */
	t_room		*room;
	unsigned	offset;
	unsigned	i;

	i = -1;
	room = *curr;
	offset = room->pre[CUR];
	room->pre[CUR] = room->pre[OLD];
	room->cost[CUR] = room->cost[OLD];
	prev = room;
	room = ROOMS + LINK_ARR[offset];
	*curr = room;
	while (++i < LINK_SIZE && ROOMS + LINK_ARR[i] != prev)
		if (((ROOMS + LINK_ARR[i])->pre[CUR] == room->index)
			&& ((ROOMS + LINK_ARR[i])->cost[CUR] == room->cost[CUR] + 1))
			backtrace_destructive(curr, prev);
}

static unsigned	choose_link(t_room *room)
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
	else if (ROOMS[LINK_ARR[i]].cost[CUR] <= room->cost[CUR] + 1)
		return (LINK_SIZE);
	else if (DEBUGP) ft_printf("On arrive sur un path on doit le remonter\n");
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
		/* else if (room != END) */
		/* 	backtrace_destructive(&room, prev); */
		else // If END is reached, go back passivly
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

	room = start;
	room->pre[CUR] = room->index;
	room->cost[CUR] = 0;
	while (1)
	{
		(DEBUGP) ? ft_printf("\n===| %s || %u |=====< %s\n", room->name, room->cost[CUR], ROOMS[room->pre[CUR]].name) : 0;
		if (room == target)
		{
			room = ROOMS + room->pre[CUR];
			(DEBUGP) ? ft_printf("we go back at end\n=======================\n") : 0;
			if (type == FULL)
				continue ;
			else
				break ;
		}
		offset = choose_link(room);
		(DEBUGP) ? ft_printf("offset = %u\n", offset) : 0;
		if ((room = traverse(start, room, offset)) == NULL)
		{
			start->cost[CUR] = 0;
			break ;
		}
		(DEBUGP) ? ft_printf("=================\n") : 0;
	}
	(DEBUGP) ? ft_printf("before finish\n") : 0;
	return (finish(target));
}
