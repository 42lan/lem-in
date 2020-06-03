/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 20:15:42 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/03 03:57:55 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "lemin.h"

void			orient_path_to(t_room *target, t_byte rev)
{
	unsigned	i;
	unsigned	j;
	t_room		*room;
	t_room		*prev;

	room = target;
	while (room->cost[CUR] != 0)
	{
		prev = ROOMS + room->pre[CUR];
		i = 0;
		while (LINK_ARR[i] != room->pre[CUR])
			++i;
		if (LINK_DIR[i] & (BLOCKED | ALLOWED))
			LINK_DIR[i] = DUPLEX;
		else
			LINK_DIR[i] = (!rev) ? ALLOWED : BLOCKED;
		j = 0;
		while (prev->link.arr[j] != room->index)
			++j;
		if (prev->link.dir[j] & (ALLOWED | BLOCKED))
			prev->link.dir[j] = DUPLEX;
		else
			prev->link.dir[j] = (!rev) ? BLOCKED : ALLOWED;
		room = prev;
	}
}
