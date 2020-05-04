/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:03:09 by amalsago          #+#    #+#             */
/*   Updated: 2020/05/04 18:30:28 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include <string.h>
#include <errno.h>

#include "lemin.h"

static unsigned		get_nb_paths(void)
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
		while (++j < room->LINK_LEN)
			if (LINK_DIR[j] == BLOCKED)
				paths++;
	}
	return (paths);
}

static unsigned		get_max_cost(unsigned *ants_by_path, unsigned nb_paths)
{
	unsigned	i;
	unsigned	cost;

	i = -1;
	cost = 0;
	while (++i < nb_paths)
	{
		ft_printf("On path %d - send %d ants\n", i, ants_by_path[i]);
		if (ants_by_path[i] > cost)
			cost = ants_by_path[i];
	}
	return (cost + 1);
}

static void			fill_remain_ants(unsigned ants, unsigned *ants_by_path, unsigned nb_paths)
{
	unsigned	k;

	k = 0;
	while (ants > 0)
	{
		if (k == nb_paths)
			k = 0;
		ants_by_path[k] += 1;
		ants -= 1;
		k++;
	}
}

static unsigned		*get_paths_len(unsigned nb_paths)
{
	unsigned	i;
	unsigned	j;
	unsigned	k;
	unsigned	*paths_len;
	t_room		*room;

	i = -1;
	k = 0;
	if (!(paths_len = (unsigned*)ft_memalloc(sizeof(unsigned) * nb_paths)))
		ft_printerr("lem-in: get_paths_len(malloc): %s\n", strerror(errno));
	while (++i < END->LINK_LEN)
	{
		j = -1;
		room = ROOMS + END->link.arr[i];
		while (++j < room->LINK_LEN)
			if (LINK_DIR[j] == BLOCKED)
			{
				paths_len[k] = room->rtil;
				k++;
			}
	}
	return (paths_len);
}

static void			dispatch_ants(unsigned *ants, unsigned *ants_by_path, unsigned nb_paths)
{
	unsigned	k;
	unsigned	diff;
	unsigned	*paths_len;

	k = 0;
	diff = 0;
	paths_len = get_paths_len(nb_paths);
	while (k < nb_paths && *ants > 0)
	{
		if (k + 1 < nb_paths)
			diff = paths_len[k + 1] - paths_len[k];
		else
			diff = 1;
		ants_by_path[k] += diff;
		*ants -= diff;
		k++;
	}
}

unsigned	get_cost(void)
{
	unsigned	ants;
	unsigned	cost;
	unsigned	nb_paths;
	unsigned	*ants_by_path;

	cost = 0;
	nb_paths = get_nb_paths();
	ants = g_farm.ants_total;
	if (!(ants_by_path = (unsigned*)ft_memalloc(sizeof(unsigned) * nb_paths)))
		ft_printerr("lem-in: get_cost(malloc): %s\n", strerror(errno));
	dispatch_ants(&ants, ants_by_path, nb_paths);
	fill_remain_ants(ants, ants_by_path, nb_paths);
	cost = get_max_cost(ants_by_path, nb_paths);
	return (cost);
}
