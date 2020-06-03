/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 19:30:43 by abaisago          #+#    #+#             */
/*   Updated: 2020/06/03 06:47:00 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void			reset_info(t_farm *f)
{
	unsigned	i;

	i = -1;
	while (++i < f->size)
	{
		f->rooms[i].pre[OLD] = -1;
		f->rooms[i].pre[CUR] = -1;
		f->rooms[i].cost[OLD] = -1;
		f->rooms[i].cost[CUR] = -1;
	}
}

void			reset_all(t_farm *f)
{
	unsigned	i;
	unsigned	j;
	t_room		*room;

	i = -1;
	while (++i < f->size)
	{
		room = f->rooms + i;
		room->pre[OLD] = -1;
		room->pre[CUR] = -1;
		room->cost[OLD] = -1;
		room->cost[CUR] = -1;
		j = -1;
		while (++j < room->lnk.lst->len)
			room->lnk.dir[j] = DUPLEX;
	}
}
