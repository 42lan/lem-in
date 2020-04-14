/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path2target.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 20:15:42 by amalsago          #+#    #+#             */
/*   Updated: 2020/04/14 20:17:35 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		print_path2target(unsigned *path, unsigned size)
{
	unsigned	i;

	i = -1;
	while (++i < size)
		ft_printf(i + 1 == size ? "%d (%s)\n" : "%d (%s) -> ", path[i],
			ROOMS[path[i]].name);
}

unsigned		*get_path2target(t_room *target)
{
	unsigned	i;
	unsigned	cost;
	unsigned	*path;
	t_room		*room;

	room = target;
	cost = target->cost[CUR];
	i = cost;
	if (!(path = (unsigned *)ft_memalloc(cost)))
		ft_printerr("lem-in: get_path2target(malloc)\n");
	while (room->flags != F_START)
	{
		path[i - 1] = room->pre[CUR];
		room = ROOMS + room->pre[CUR];
		i--;
	}
	print_path2target(path, cost);
	return (path);
}
