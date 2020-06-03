/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 03:27:51 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/03 07:12:11 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static unsigned	not_exception(t_farm *f, t_room *room)
{
	if (room != f->start && room != f->end && !(room->flags & F_DEAD))
		return (SUCCESS);
	return (FAILURE);
}

static void		remove_deadend_helper(t_farm *f, t_byte *con)
{
	unsigned	i;
	unsigned	j;
	unsigned	k;
	t_room		*room;

	i = -1;
	while (++i < f->size)
	{
		j = -1;
		k = 0;
		room = &f->rooms[i];
		if (not_exception(f, room) == SUCCESS)
		{
			while (++j < room->lnk.lst->len)
				if (!(f->rooms[room->lnk.arr[j]].flags & F_DEAD))
					k++;
			if (k < 2)
			{
				room->flags |= F_DEAD;
				*con = 1;
			}
		}
	}
}

void			remove_deadend(t_farm *f)
{
	t_byte		con;

	con = 1;
	while (con)
	{
		con = 0;
		remove_deadend_helper(f, &con);
	}
}
