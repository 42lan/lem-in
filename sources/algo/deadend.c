/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 03:27:51 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/03 03:33:06 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void			remove_deadend_helper(t_byte *con)
{
	unsigned	i;
	unsigned	j;
	unsigned	k;
	t_room		*room;

	i = -1;
	while (++i < g_farm.size)
	{
		j = -1;
		k = 0;
		room = &ROOMS[i];
		if (room != START && room != END && !(room->flags & F_DEAD))
		{
			while (++j < room->LINK_LEN)
				if (!(ROOMS[LINK_ARR[j]].flags & F_DEAD))
					k++;
			if (k < 2)
			{
				room->flags |= F_DEAD;
				*con = 1;
			}
		}
	}
}

void			remove_deadend(void)
{
	t_byte		con;

	con = 1;
	while (con)
	{
		con = 0;
		remove_deadend_helper(&con);
	}
}
