/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 10:03:09 by amalsago          #+#    #+#             */
/*   Updated: 2020/05/06 14:15:45 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "lib.h"
#include "lemin.h"
#include "colors.h"

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
		while (++j < LINK_SIZE)
			if (ROOMS + LINK_ARR[j] == END && LINK_DIR[j] == BLOCKED)
				paths++;
	}
	return (paths);
}

static unsigned		get_max_cost(unsigned *ants_by_path, unsigned *paths_len,
						unsigned nb_paths)
{
	unsigned	i;
	unsigned	cost;

	i = -1;
	cost = 0;
	/* ft_printf("-------------------------------------\n"); */
	while (++i < nb_paths)
	{
		cost = (ants_by_path[i] + paths_len[i]) - 1;
		/* ft_printf("| SENDING %d ANTS ON PATH %d (WITH %d ROOMS) WILL COST %d\n", */
		/* 	ants_by_path[i], i, paths_len[i] + 1, cost + 1); */
	}
	/* ft_printf("-------------------------------------\n"); */
	return (cost + 1);
}

static void			fill_remain_ants(unsigned ants, unsigned *ants_by_path,
						unsigned nb_paths)
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

static void			sort_paths_len(unsigned *paths_len, unsigned nb_paths)
{
	unsigned	i;

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
		while (++j < LINK_SIZE)
		{
			if (LINK_DIR[j] == BLOCKED)
			{
				paths_len[k] = room->rtil;
				k++;
			}
		}
	}
	sort_paths_len(paths_len, nb_paths);
	return (paths_len);
}

static void			dispatch_ants(unsigned *ants, unsigned *ants_by_path,
						unsigned *paths_len, unsigned nb_paths)
{
	unsigned	j;
	unsigned	k;
	unsigned	diff;

	k = 0;
	while (nb_paths > 1 && *ants > 0 && k < nb_paths)
	{
		if (k + 1 < nb_paths)
		{
			diff = paths_len[k + 1] - paths_len[k];
			if (k != 0)
			{
				j = -1;
				while (*ants > 0 && ++j < k)
				{
					if ((int)(*ants - diff) < 0)
						break ;
					ants_by_path[j] += diff;
					*ants -= diff;
				}
			}
		}
		else
			diff = 1;
		if ((int)(*ants - diff) < 0)
			break ;
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
	unsigned	*paths_len;
	unsigned	*ants_by_path;

	cost = 0;
	nb_paths = get_nb_paths();
	ants = g_farm.ants_total;
	if (!(ants_by_path = (unsigned*)ft_memalloc(sizeof(unsigned) * nb_paths)))
		ft_printerr("lem-in: get_cost(malloc): %s\n", strerror(errno));
	paths_len = get_paths_len(nb_paths);
	dispatch_ants(&ants, ants_by_path, paths_len, nb_paths);
	fill_remain_ants(ants, ants_by_path, nb_paths);
	cost = get_max_cost(ants_by_path, paths_len, nb_paths);
	free(paths_len);
	free(ants_by_path);
	return (cost);
}
