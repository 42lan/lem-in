/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:03:09 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/03 03:41:00 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "lib.h"
#include "lemin.h"
#include "colors.h"

static void			fill_remain_ants(unsigned ants, unsigned *ants_by_path,
						unsigned nb_paths)
{
	unsigned		k;

	while (ants > 0)
	{
		k = -1;
		while (++k < nb_paths && ants > 0)
		{
			ants_by_path[k] += 1;
			ants -= 1;
		}
	}
}

static void			sort_paths_len(unsigned *paths_len, unsigned nb_paths)
{
	unsigned		i;

	i = -1;
	while (++i < nb_paths - 1)
		if (paths_len[i] > paths_len[i + 1])
		{
			ft_swap_xor(&paths_len[i], &paths_len[i + 1]);
			i = -1;
		}
}

static unsigned		*get_paths_len(unsigned nb_paths)
{
	unsigned		i;
	unsigned		j;
	unsigned		k;
	unsigned		*paths_len;
	t_room			*room;

	i = -1;
	k = -1;
	if (!(paths_len = (unsigned*)ft_memalloc(sizeof(unsigned) * nb_paths)))
		ft_printerr("lem-in: get_paths_len(malloc): %s\n", strerror(errno));
	while (++i < END->LINK_LEN)
		if (END->link.dir[i] == ALLOWED)
		{
			j = -1;
			paths_len[++k] = 1;
			room = ROOMS + END->link.arr[i];
			while (++j < room->LINK_LEN)
				if (room->link.dir[j] == ALLOWED)
				{
					room = ROOMS + room->link.arr[j];
					paths_len[k] += 1;
					j = -1;
				}
			(ROOMS + END->link.arr[i])->cost[CUR] = paths_len[k];
		}
	return (paths_len);
}

static void			dispatch_ants(unsigned *ants, unsigned *ants_by_path,
						unsigned *paths_len, unsigned nb_paths)
{
	unsigned		j;
	unsigned		k;
	unsigned		diff;

	k = 0;
	diff = 0;
	while (nb_paths > 1 && *ants > diff && k < nb_paths - 1)
	{
		j = -1;
		diff = paths_len[k + 1] - paths_len[k];
		if (diff > *ants)
			diff = *ants;
		while (*ants > diff && ++j < k + 1)
		{
			ants_by_path[j] += diff;
			*ants -= diff;
		}
		k++;
	}
	fill_remain_ants(*ants, g_farm.ants_by_path, nb_paths);
}

unsigned			get_cost(void)
{
	unsigned		ants;
	unsigned		cost;
	unsigned		nb_paths;
	unsigned		*paths_len;

	cost = 0;
	nb_paths = get_nb_paths();
	g_farm.nb_paths = nb_paths;
	ants = g_farm.ants_total;
	if (g_farm.ants_by_path != NULL)
		free(g_farm.ants_by_path);
	if (!(g_farm.ants_by_path = (unsigned*)ft_memalloc(
		sizeof(unsigned) * nb_paths)))
		ft_printerr("lem-in: get_cost(malloc): %s\n", strerror(errno));
	paths_len = get_paths_len(nb_paths);
	sort_paths_len(paths_len, nb_paths);
	dispatch_ants(&ants, g_farm.ants_by_path, paths_len, nb_paths);
	cost = get_max_cost(g_farm.ants_by_path, paths_len, nb_paths);
	free(paths_len);
	return (cost);
}
