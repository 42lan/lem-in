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

#include <limits.h>

static	t_room	get_start(t_farm farm)
{
	unsigned	i;

	i = -1;
	while (++i < farm.size)
		if (farm.rooms[i].flags & F_START)
			return (farm.rooms[i]);
	return (farm.rooms[0]);
}

void	dfs(t_farm farm)
{
	t_room		node;
	unsigned	prev;
	unsigned	i;

	node = get_start(farm);
	ft_printf("start is %s\n", node.name);
	farm.rooms[node.index].pre[0] = node.index;
	while ((node.flags & F_END) == 0)
	{
		ft_printf("======== %s =========\n", node.name);
		prev = node.index;
		i = -1;
		while (((farm.rooms[node.link.arr[++i]]).pre[0] != UINT_MAX)
			&& i < node.link.list->len)
			;
		ft_printf("On arrete la while sur le lien numero %d qui est %s\n"
			"La size est %d\n", i, farm.rooms[node.link.arr[i]].name,
			node.link.list->len);
		if (i == node.link.list->len)
		{
			ft_printf("we go back because we are on a dead end\n");
			node = farm.rooms[node.pre[0]];
		}
		else
		{
			ft_printf("We go deeper\n");
			node = farm.rooms[node.link.arr[i]];
		}
		if (node.pre[0] == UINT_MAX)
			farm.rooms[node.index].pre[0] = prev;
		ft_printf("=================\n\n", node.name);
	}
	ft_printf("Le DFS est fini!\n");
}
