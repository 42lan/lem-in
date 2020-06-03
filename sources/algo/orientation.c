/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 20:15:42 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/03 06:40:52 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "lemin.h"

void			orient_path_to(t_farm *f, t_room *target, t_byte rev)
{
	unsigned	i;
	unsigned	j;
	t_room		*room;
	t_room		*prev;

	room = target;
	while (room->cost[CUR] != 0)
	{
		prev = f->rooms + room->pre[CUR];
		i = 0;
		while (room->lnk.arr[i] != room->pre[CUR])
			++i;
		if (room->lnk.dir[i] & (BLOCKED | ALLOWED))
			room->lnk.dir[i] = DUPLEX;
		else
			room->lnk.dir[i] = (!rev) ? ALLOWED : BLOCKED;
		j = 0;
		while (prev->lnk.arr[j] != room->index)
			++j;
		if (prev->lnk.dir[j] & (ALLOWED | BLOCKED))
			prev->lnk.dir[j] = DUPLEX;
		else
			prev->lnk.dir[j] = (!rev) ? BLOCKED : ALLOWED;
		room = prev;
	}
}
