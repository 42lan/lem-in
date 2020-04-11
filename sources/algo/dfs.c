/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:11:29 by abosch            #+#    #+#             */
/*   Updated: 2020/04/11 16:48:33 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include <limits.h>

static	t_room	get_start(t_farm farm)
{
	unsigned	i;

	i = -1;
	while (++i < farm.size)
	{
		ft_printf("flags room %d : %d\n", i, farm.rooms[i].flags);
		if (farm.rooms[i].flags & F_START)
		{
			ft_printf("coucou\n");
			return (farm.rooms[i]);
		}
	}
	return (farm.rooms[0]);
}

void	dfs(t_farm farm)
{
	t_room		node;
	unsigned	prev;
	unsigned	i;

	ft_printf("starting dfs\n");
	node = get_start(farm);
	ft_printf("start is %s\n", node.name);
	node.pre[0] = node.index;
	while ((node.flags & F_END) == 0)
	{
		ft_printf("We are on node %s and the predecesor is %u\n", node.name, node.pre[0]);
		prev = node.index;
		i = -1;
		while (farm.rooms[node.link.arr[++i]].pre[0] != UINT_MAX
			&& i < node.link.list->size)
			;
		if (i == node.link.list->size)
		{
			ft_printf("we go back because we are on a dead end\n");
			node = farm.rooms[node.pre[0]];
		}
		else
		{
			ft_printf("We go deeper\n");
			node = farm.rooms[node.link.arr[i]];
		}
		if (node.pre[0] != UINT_MAX)
			node.pre[0] = prev;
	}
	ft_printf("yesai\n");
}
