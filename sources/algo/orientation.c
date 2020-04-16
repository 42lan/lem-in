/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 20:15:42 by amalsago          #+#    #+#             */
/*   Updated: 2020/04/16 13:56:36 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "debug.h" // DEL
#include "lemin.h"

void	orient_path_to(t_room *target)
{
	t_room		*room;
	t_room		*prev;
	unsigned	i;

	room = target;
	while (room->cost[CUR] != 0)
	{
		prev = ROOMS + room->pre[CUR];
		i = -1;
		while (prev->link.arr[++i] != room->index)
			;
		prev->link.dir[i] = INWARD;
		room = prev;
	}
	print_paths_from(room);
}
