/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 20:15:42 by amalsago          #+#    #+#             */
/*   Updated: 2020/04/16 14:46:54 by abaisago         ###   ########.fr       */
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
	unsigned	j;

	room = target;
	while (room->cost[CUR] != 0)
	{
		prev = ROOMS + room->pre[CUR];
		i = 0;
		while (LINK_ARR[i] != room->pre[CUR])
			++i;
		if (LINK_DIR[i] == INWARD)
			LINK_DIR[i] = UNSET;
		else
		{
			j = 0;
			while (prev->link.arr[j] != room->index)
				++j;
			prev->link.dir[j] = INWARD;
			room = prev;
		}
	}
	print_paths_from(room);
}
