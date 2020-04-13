/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:11:29 by abosch            #+#    #+#             */
/*   Updated: 2020/04/13 21:41:32 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "lemin.h"

#include <limits.h>

int		dfs(t_room *start, t_room *target, t_byte type)
{
	t_room		*room;
	unsigned	prev;
	unsigned	cost;
	unsigned	i;

	room = start;
	room->pre[CUR] = room->index;
	room->cost[CUR] = (cost = 0);
	while (1)
	{
		ft_printf("\n===| %s || %u |=====< %s\n",
			room->name, room->cost[CUR], ROOMS[room->pre[CUR]].name);
		if (room == target)
		{
			--cost;
			room = ROOMS + room->pre[CUR];
			ft_printf("we go back at end\n=======================\n");
			if (type == FULL)
				continue ;
			else
				break ;
		}
		prev = room->index;
		i = 0;
		while ((cost + 1 > ROOMS[LINK_ARR[i]].cost[CUR]
			|| ROOMS[LINK_ARR[i]].pre[CUR] == room->index) && i < LINK_SIZE)
			++i;
		ft_printf("while: %u/%u -> %s:%u\n", i + 1, LINK_SIZE,
			ROOMS[LINK_ARR[i]].name, ROOMS[LINK_ARR[i]].cost[CUR]);
		if (i == LINK_SIZE)
		{
			if (room == start)
				break;
			else
			{
				--cost;
				room = ROOMS + room->pre[CUR];
				ft_printf("we go back\n");
			}
		}
		else
		{
			++cost;
			room = ROOMS + LINK_ARR[i];
			room->pre[OLD] = room->pre[CUR];
			room->cost[OLD] = room->cost[CUR];
			room->pre[CUR] = prev;
			room->cost[CUR] = cost;
			ft_printf("We go deeper\n");
		}
		ft_printf("=================\n");
	}
	if (target->pre[CUR] == UINT_MAX)
	{
		ft_printf("\nDFS: failure, target :|%s|: not found\n", target->name);
		return (FAILURE);
	}
	else
	{
		ft_printf("\nDFS: success, target :|%s|: found with cost= %u\n",
			target->name, target->cost[CUR]);
		return (SUCCESS);
	}
}
