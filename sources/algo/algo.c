/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 22:01:45 by abaisago          #+#    #+#             */
/*   Updated: 2020/06/01 14:47:03 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "debug.h"
#include "lemin.h"
#include "tools.h"

#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

static void		update_link(t_room *room, t_room *target, t_byte state)
{
	unsigned	i;

	i = -1;
	while (++i < LINK_SIZE)
		if (ROOMS + LINK_ARR[i] == target)
			LINK_DIR[i] = state;
}

static int		resolve_trivial(void)
{
	unsigned	i;

	i = -1;
	update_link(START, END, BLOCKED);
	update_link(END, START, ALLOWED);
	g_farm.nb_paths = 1;
	if (!(g_farm.ants_by_path = (unsigned*)ft_memalloc(sizeof(unsigned) * 1)))
		return (ft_dprintf(STDERR_FILENO, "lem-in: resolve_onemove(malloc)\n"));
	g_farm.ants_by_path[0] = g_farm.ants_total;
	return (SUCCESS);
}

static t_byte	is_mixed_path(void)
{
	unsigned	i;
	unsigned	j;
	unsigned	k;
	t_room		*room;
	t_room		*next;

	i = -1;
	room = NULL;
	next = NULL;
	while (++i < END->LINK_LEN)
		if (END->link.dir[i] == ALLOWED)
		{
			room = ROOMS + END->link.arr[i];
			while (room != START)
			{
				/* ft_printf("actual room = %s\n", room->name); */
				j = -1;
				k = 0;
				while (++j < LINK_SIZE)
					if (LINK_DIR[j] == ALLOWED)
					{
						k++;
						/* ft_printf("link = %s\n", (ROOMS+LINK_ARR[j])->name); */
						next = ROOMS + LINK_ARR[j];
					}
				/* ft_printf("k = %d\n", k); */
				if (k > 1)
					return (1);
				/* ft_printf("next room = %s\n", room->name); */
				room = next;
				/* ft_printf("\n"); */
			}
		}
	return (0);
}

static void		resolve_nontrivial_helper(void)
{

	get_cost();
	if (g_farm.nb_paths > 1)
	{
		if (is_mixed_path() == 1)
			ft_printf("We have a problem\n");
		sort_paths();
	}
}

static int		resolve_nontrivial(void)
{
	unsigned	curr_cost;
	unsigned	last_cost;

	curr_cost = 0;
	last_cost = UINT_MAX;
	if (dfs(g_farm.start, g_farm.end, FIRST) == FAILURE)
		return (ft_dprintf(STDERR_FILENO, E_MAP));
	reset_info();
	while (dfs(g_farm.start, g_farm.end, FULL) == SUCCESS)
	{
		orient_path_to(END, REV_NO);
		curr_cost = get_cost();
		if (curr_cost > last_cost)
		{
			orient_path_to(END, REV_YES);
			break ;
		}
		last_cost = curr_cost;
		reset_info();
	}
	resolve_nontrivial_helper();
	return (SUCCESS);
}

int		resolve(void)
{
	if (start_links_end() == SUCCESS)
		return (resolve_trivial());
	else
		return (resolve_nontrivial());
}
