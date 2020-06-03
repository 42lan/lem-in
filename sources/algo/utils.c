/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 14:47:17 by abosch            #+#    #+#             */
/*   Updated: 2020/06/03 06:30:52 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void			recount_cost(t_farm *f)
{
	unsigned	i;
	unsigned	j;
	unsigned	cost;
	t_room		*room;

	i = -1;
	while (++i < f->start->lnk.lst->len)
		if (f->start->lnk.dir[i] == BLOCKED)
		{
			j = -1;
			cost = 0;
			room = f->rooms + f->start->lnk.arr[i];
			room->cost[CUR] = ++cost;
			while (++j < room->lnk.lst->len)
				if (room->lnk.dir[j] == BLOCKED)
				{
					room = f->rooms + room->lnk.arr[j];
					room->cost[CUR] = ++cost;
					j = -1;
				}
		}
}

unsigned		get_nb_paths(t_farm *f)
{
	unsigned	i;
	unsigned	j;
	unsigned	paths;
	t_room		*room;

	i = -1;
	paths = 0;
	while (++i < f->end->lnk.lst->len)
	{
		j = -1;
		room = f->rooms + f->end->lnk.arr[i];
		while (++j < room->lnk.lst->len)
			if (f->rooms + room->lnk.arr[j] == f->end && room->lnk.dir[j] == BLOCKED)
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

t_byte			is_mixed_path(t_farm *f)
{
	unsigned	i;
	unsigned	j;
	unsigned	k;
	t_room		*room;
	t_room		*next;

	i = -1;
	while (++i < f->end->lnk.lst->len)
		if (f->end->lnk.dir[i] == ALLOWED)
		{
			room = f->rooms + f->end->lnk.arr[i];
			while (room != f->start)
			{
				j = -1;
				k = 0;
				while (++j < room->lnk.lst->len)
					if (room->lnk.dir[j] == ALLOWED)
					{
						k++;
						next = f->rooms + room->lnk.arr[j];
					}
				if (k > 1)
					return (SUCCESS);
				room = next;
			}
		}
	return (FAILURE);
}
