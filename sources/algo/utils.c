/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 14:47:17 by abosch            #+#    #+#             */
/*   Updated: 2020/05/22 13:12:39 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void			remove_deadend(void)
{
	unsigned	i;
	unsigned	j;
	unsigned	k;
	t_room		*room;
	t_byte		con;

	con = 1;
	while (con)
	{
		i = -1;
		con = 0;
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
					con = 1;
				}
			}
		}
	}
}

void			recount_cost(void)
{
	unsigned	i;
	unsigned	j;
	unsigned	cost;
	t_room		*room;

	i = -1;
	while (++i < START->LINK_LEN)
		if (START->link.dir[i] == BLOCKED)
		{
			j = -1;
			cost = 0;
			room = ROOMS + START->link.arr[i];
			room->cost[CUR] = ++cost;
			while (++j < LINK_SIZE)
				if (LINK_DIR[j] == BLOCKED)
				{
					room = ROOMS + LINK_ARR[j];
					room->cost[CUR] = ++cost;
					j = -1;
				}
		}
}

unsigned		get_nb_paths(void)
{
	unsigned	i;
	unsigned	j;
	unsigned	paths;
	t_room		*room;

	i = -1;
	paths = 0;
	while (++i < END->LINK_LEN)
	{
		j = -1;
		room = ROOMS + END->link.arr[i];
		while (++j < LINK_SIZE)
			if (ROOMS + LINK_ARR[j] == END && LINK_DIR[j] == BLOCKED)
				paths++;
	}
	return (paths);
}

unsigned		get_max_cost(unsigned *ants_by_path, unsigned *paths_len,
					unsigned nb_paths)
{
	unsigned	i;
	unsigned	cost;

	i = -1;
	cost = 0;
	while (++i < nb_paths)
		cost = ants_by_path[i] + paths_len[i] - 1;
	return (cost);
}
