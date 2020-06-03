/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 22:01:45 by abaisago          #+#    #+#             */
/*   Updated: 2020/06/03 04:36:24 by amalsago         ###   ########.fr       */
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
	update_link(START, END, BLOCKED);
	update_link(END, START, ALLOWED);
	g_farm.nb_paths = 1;
	if (!(g_farm.ants_by_path = (unsigned*)ft_memalloc(sizeof(unsigned) * 1)))
		return (ft_dprintf(STDERR_FILENO, "lem-in: resolve_onemove(malloc)\n"));
	g_farm.ants_by_path[0] = g_farm.ants_total;
	return (SUCCESS);
}


static int		resolve_nontrivial_helper(void)
{

	get_cost();
	if (g_farm.nb_paths > 1)
	{
		if (is_mixed_path() == SUCCESS)
			return (FAILURE);
		sort_paths();
	}
	return (SUCCESS);
}

static int		resolve_nontrivial(t_byte type)
{
	unsigned	curr_cost;
	unsigned	last_cost;

	curr_cost = 0;
	last_cost = UINT_MAX;
	if (dfs(g_farm.start, g_farm.end, FIRST) == FAILURE)
		return (ft_dprintf(STDERR_FILENO, E_MAP));
	reset_info();
	while (dfs(g_farm.start, g_farm.end, type) == SUCCESS)
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
	return (resolve_nontrivial_helper());
}

int				resolve(void)
{
	unsigned	status;

	if (start_links_end() == SUCCESS)
		return (resolve_trivial());
	else
	{
		status = resolve_nontrivial(FULL);
		if (status == FAILURE)
		{
			reset_all();
			return (resolve_nontrivial(SIMPLE));
		}
		return ((status != SUCCESS) ? FAILURE : SUCCESS);
	}
}
