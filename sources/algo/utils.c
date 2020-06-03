/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 14:47:17 by abosch            #+#    #+#             */
/*   Updated: 2020/06/03 04:54:17 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

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

t_byte			is_mixed_path(void)
{
	unsigned	i;
	unsigned	j;
	unsigned	k;
	t_room		*room;
	t_room		*next;

	i = -1;
	while (++i < END->LINK_LEN)
		if (END->link.dir[i] == ALLOWED)
		{
			room = ROOMS + END->link.arr[i];
			while (room != START)
			{
				j = -1;
				k = 0;
				while (++j < LINK_SIZE)
					if (LINK_DIR[j] == ALLOWED)
					{
						k++;
						next = ROOMS + LINK_ARR[j];
					}
				if (k > 1)
					return (SUCCESS);
				room = next;
			}
		}
	return (FAILURE);
}
