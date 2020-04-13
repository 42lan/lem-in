/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:11:29 by abosch            #+#    #+#             */
/*   Updated: 2020/04/13 14:41:05 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "lemin.h"

#include <limits.h>

void	dfs()
{
	t_room		*room;
	unsigned	prev;
	unsigned	i;

	room = g_farm.start;
	ft_printf("start is :|%s|:\n", room->name);
	room->pre[CUR] = room->index;
	while ((room->flags & F_END) == 0)
	{
		ft_printf("======== %s =========\n", room->name);
		prev = room->index;
		i = 0;
		while (ROOMS[LINK_ARR[i]].pre[CUR] != UINT_MAX && i < LINK_SIZE)
			++i;
		ft_printf("On arrete la while sur le lien numero %d qui est %s\n"
			"La size est %d\n", i, ROOMS[LINK_ARR[i]].name, LINK_SIZE);
		if (i == LINK_SIZE)
		{
			ft_printf("we go back because we are on a dead end\n");
			room = ROOMS + room->pre[CUR];
		}
		else
		{
			ft_printf("We go deeper\n");
			room = ROOMS + LINK_ARR[i];
		}
		if (room->pre[CUR] == UINT_MAX)
			room->pre[CUR] = prev;
		ft_printf("=================\n\n");
	}
	ft_printf("Le DFS est fini sur :|%s|:!\n", room->name);
}
