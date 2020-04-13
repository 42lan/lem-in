/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:11:29 by abosch            #+#    #+#             */
/*   Updated: 2020/04/13 16:52:26 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "lemin.h"

#include <limits.h>

int		dfs(t_room *start, t_room *target)
{
	t_room		*room;
	unsigned	prev;
	unsigned	cost;
	unsigned	i;

	room = start;
	room->pre[CUR] = room->index;
	room->cost[CUR] = (cost = 0);
	while (room != target)
	{
		ft_printf("\n======| %s |=========< %u:%s\n",
			room->name, room->cost[CUR], ROOMS[room->pre[CUR]].name);
		prev = room->index;
		i = 0;
		while (ROOMS[LINK_ARR[i]].pre[CUR] != UINT_MAX && i < LINK_SIZE)
			++i;
		if (i >= LINK_SIZE)
			break;
		ft_printf("while: %u/%u -> %s\n", i + 1, LINK_SIZE, ROOMS[LINK_ARR[i]].name);
		if (i == LINK_SIZE || ROOMS[LINK_ARR[i]].cost[CUR] <= cost + 1)
		{
			--cost;
			room->pre[CUR] = room->pre[OLD];
			room->cost[CUR] = room->cost[OLD];
			room = ROOMS + room->pre[CUR];
			ft_printf("we go back\n");
		}
		else
		{
			++cost;
			room = ROOMS + LINK_ARR[i];
			room->pre[CUR] = prev;
			room->cost[CUR] = cost;
			ft_printf("We go deeper\n");
		}
		ft_printf("=================\n");
	}
	if (room != target)
	{
		ft_printf("\nDFS: failure, target :|%s|: not found\n", target->name);
		return (FAILURE);
	}
	else
	{
		ft_printf("\nDFS: success, target :|%s|: found\n", room->name);
		return (SUCCESS);
	}
}
