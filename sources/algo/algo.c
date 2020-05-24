/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 22:01:45 by abaisago          #+#    #+#             */
/*   Updated: 2020/05/24 22:59:38 by amalsago         ###   ########.fr       */
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

int		resolve_onemove(void)
{
	unsigned	i;

	i = -1;
	while (++i < END->link.list->len)
		if (ROOMS + END->link.arr[i] == START)
			END->link.dir[i] = ALLOWED;
	g_farm.nb_paths = 1;
	if (!(g_farm.ants_by_path = (unsigned*)ft_memalloc(sizeof(unsigned) * 1)))
		return (ft_dprintf(STDERR_FILENO, "lem-in: resolve_onemove(malloc)\n"));
	g_farm.ants_by_path[0] = g_farm.ants_total;
	return (SUCCESS);
}

int		resolve(void)
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
	get_cost();
	return (SUCCESS);
}
