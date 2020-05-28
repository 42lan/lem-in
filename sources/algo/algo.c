/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 22:01:45 by abaisago          #+#    #+#             */
/*   Updated: 2020/05/28 09:54:45 by amalsago         ###   ########.fr       */
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
		if (DEBUGP)
		{
			ft_printf("=================================\n");
			print_paths_from(g_farm.start);
			ft_printf("=================================\n");
		}
		curr_cost = get_cost();
		if (curr_cost > last_cost)
		{
			orient_path_to(END, REV_YES);
			break ;
		}
		last_cost = curr_cost;
		reset_info();
	}
	get_cost();
	return (SUCCESS);
}

int		resolve(void)
{
	if (start_links_end() == SUCCESS)
		return (resolve_trivial());
	else
		return (resolve_nontrivial());
}
