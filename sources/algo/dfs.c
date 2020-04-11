/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:11:29 by abosch            #+#    #+#             */
/*   Updated: 2020/04/11 17:59:13 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "lemin.h"

#include <limits.h>

void	dfs()
{
	t_room		*node;
	unsigned	prev;
	unsigned	i;

	node = g_farm.start;
	ft_printf("start is %s\n", node->name);
	g_farm.rooms[node->index].pre[0] = node->index;
	while ((node->flags & F_END) == 0)
	{
		ft_printf("======== %s =========\n", node->name);
		prev = node->index;
		i = 0;
		while (g_farm.rooms[node->link.arr[i]].pre[0] != UINT_MAX
			&& i < node->link.list->len)
			++i;
		ft_printf("On arrete la while sur le lien numero %d qui est %s\n"
			"La size est %d\n", i, g_farm.rooms[node->link.arr[i]].name,
			node->link.list->len);
		if (i == node->link.list->len)
		{
			ft_printf("we go back because we are on a dead end\n");
			node = &g_farm.rooms[node->pre[0]];
		}
		else
		{
			ft_printf("We go deeper\n");
			node = &g_farm.rooms[node->link.arr[i]];
		}
		if (node->pre[0] == UINT_MAX)
			g_farm.rooms[node->index].pre[0] = prev;
		ft_printf("=================\n\n", node->name);
	}
	ft_printf("Le DFS est fini!\n");
}
