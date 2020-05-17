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

#include <limits.h>

static unsigned	choose_link(t_room *room)
{
	unsigned	i;
	unsigned	j;

	i = 0;
	j = 0;
//	ft_printf("choose_link\n");
	while (i < LINK_SIZE && LINK_DIR[i] != ALLOWED)
	{
		ft_printf("i = %d\n", i);
		++i;
	}
	while (j < ROOMS[room->pre[CUR]].link.list->len && ROOMS[room->pre[CUR]].link.dir[j] == DUPLEX)
	{
		ft_printf("j = %d\n", j);
		++j;
	}
	if (i == LINK_SIZE || j < ROOMS[room->pre[CUR]].link.list->len)
	{
		ft_printf("coucou bob\n");
		i = 0;
		while (i < LINK_SIZE
			&& (ROOMS[LINK_ARR[i]].flags & F_DEAD
			|| room->cost[CUR] + 1 >= ROOMS[LINK_ARR[i]].cost[CUR]
			|| LINK_DIR[i] == BLOCKED))
			++i;
		/* ft_printf("while: %u/%u -> %s:%u\n", i + 1, LINK_SIZE, */
		/* 	ROOMS[LINK_ARR[i]].name, ROOMS[LINK_ARR[i]].cost[CUR]); */
	}
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
			ft_printf("we go back\n");
		}
	}
	else
	{
		room = ROOMS + LINK_ARR[offset];
		room->pre[OLD] = room->pre[CUR];
		room->cost[OLD] = room->cost[CUR];
		room->pre[CUR] = prev->index;
		room->cost[CUR] = prev->cost[CUR] + 1;
		ft_printf("We go deeper\n");
	}
	return (room);
}

static int		finish(t_room *target)
{
	if (target->pre[CUR] == UINT_MAX)
	{
		ft_printf("\nDFS: failure, target :|%s|: not found\n", target->name);
		return (FAILURE);
	}
	else
	{
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
		ft_printf("\n===| %s || %u |=====< %s\n",
		room->name, room->cost[CUR], ROOMS[room->pre[CUR]].name);
		if (room == target)
		{
			room = ROOMS + room->pre[CUR];
			ft_printf("we go back at end\n=======================\n");
			if (type == FULL)
				continue ;
			else
				break ;
		}
		offset = choose_link(room);
		/*ft_printf("offset = %u\n", offset);*/
		if ((room = traverse(start, room, offset)) == NULL)
			break ;
		ft_printf("=================\n");
	}
	/*ft_printf("before finish\n");*/
	return (finish(target));
}
