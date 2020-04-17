/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 20:15:42 by amalsago          #+#    #+#             */
/*   Updated: 2020/04/17 19:05:44 by abaisago         ###   ########.fr       */
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
		if (LINK_DIR[i] == BLOCKED)
			LINK_DIR[i] = DUPLEX;
		else
			LINK_DIR[i] = ALLOWED;
		j = 0;
		while (prev->link.arr[j] != room->index)
			++j;
		if (prev->link.dir[j] == ALLOWED)
			prev->link.dir[j] = DUPLEX;
		else
			prev->link.dir[j] = BLOCKED;
		room = prev;
	}
}
