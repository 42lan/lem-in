/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:11:29 by abosch            #+#    #+#             */
/*   Updated: 2020/05/08 19:12:26 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "lemin.h"

#include "debug.h"

#include <limits.h>

static unsigned	choose_link(t_room *room, t_room *prev)
{
	unsigned	i;
	unsigned	j;

	i = 0;
	j = 0;
//	show_orien(room);
	while (i < LINK_SIZE && LINK_DIR[i] != ALLOWED)
		++i;
//	ft_printf("i = %d\n", i);
	while (j < prev->link.list->len && prev->link.dir[j] == DUPLEX)
		++j;
//	ft_printf("j = %d\n", j);
	if (i == LINK_SIZE || j < prev->link.list->len)
	{
//		ft_printf("cas standard\n");
		i = 0;
		while (i < LINK_SIZE
			&& (ROOMS[LINK_ARR[i]].flags & F_DEAD
			|| room->cost[CUR] + 1 >= ROOMS[LINK_ARR[i]].cost[CUR]
			|| LINK_DIR[i] == BLOCKED))
			++i;
		/* ft_printf("while: %u/%u -> %s:%u\n", i + 1, LINK_SIZE, */
		/* 	ROOMS[LINK_ARR[i]].name, ROOMS[LINK_ARR[i]].cost[CUR]); */
	}
//	else
//		ft_printf("On arrive sur un path on doit le remonter\n");
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
//			ft_printf("we go back\n");
		}
	}
	else
	{
		room = ROOMS + LINK_ARR[offset];
		room->pre[OLD] = room->pre[CUR];
		room->cost[OLD] = room->cost[CUR];
		room->pre[CUR] = prev->index;
		room->cost[CUR] = prev->cost[CUR] + 1;
//		ft_printf("We go deeper\n");
	}
	return (room);
}

static int		finish(t_room *target)
{
	if (target->pre[CUR] == UINT_MAX)
	{
//		ft_printf("\nDFS: failure, target :|%s|: not found\n", target->name);
		return (FAILURE);
	}
	else
	{
//		ft_printf("\nDFS: success, target :|%s|: (%u steps)\n",
//		 	target->name, target->cost[CUR]);
		return (SUCCESS);
	}
}

int		dfs(t_room *start, t_room *target, t_byte type)
{
	t_room		*room;
	t_room		*prev;
	unsigned	offset;

	room = start;
	prev = room;
	room->pre[CUR] = room->index;
	room->cost[CUR] = 0;
	while (1)
	{
//		ft_printf("\n===| %s || %u |=====< %s\n",
//		room->name, room->cost[CUR], ROOMS[room->pre[CUR]].name);
		if (room == target)
		{
			room = ROOMS + room->pre[CUR];
//			ft_printf("we go back at end\n=======================\n");
			if (type == FULL)
				continue ;
			else
				break ;
		}
		offset = choose_link(room, prev);
//		ft_printf("offset = %u\n", offset);
		prev = room;
		if ((room = traverse(start, room, offset)) == NULL)
		{
			start->cost[CUR] = 0;
			break ;
		}
//		ft_printf("=================\n");
	}
//	ft_printf("before finish\n");
	return (finish(target));
}
