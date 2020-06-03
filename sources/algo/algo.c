/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 22:01:45 by abaisago          #+#    #+#             */
/*   Updated: 2020/06/03 07:16:35 by amalsago         ###   ########.fr       */
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

static void		update_link(t_farm *f, t_room *room, t_room *target, t_byte dir)
{
	unsigned	i;

	i = -1;
	while (++i < room->lnk.lst->len)
		if (f->rooms + room->lnk.arr[i] == target)
			room->lnk.dir[i] = dir;
}

static int		resolve_trivial(t_farm *f)
{
	update_link(f, f->start, f->end, BLOCKED);
	update_link(f, f->end, f->start, ALLOWED);
	f->nb_paths = 1;
	if (!(f->ants_by_path = (unsigned*)ft_memalloc(sizeof(unsigned) * 1)))
		return (ft_dprintf(STDERR_FILENO, "lem-in: resolve_onemove(malloc)\n"));
	f->ants_by_path[0] = f->ants_total;
	return (SUCCESS);
}

static int		resolve_nontrivial_helper(t_farm *f)
{
	get_cost(f);
	if (f->nb_paths > 1)
	{
		if (is_mixed_path(f) == SUCCESS)
			return (FAILURE);
		sort_paths();
	}
	return (SUCCESS);
}

static int		resolve_nontrivial(t_farm *f, t_byte type)
{
	unsigned	curr_cost;
	unsigned	last_cost;

	curr_cost = 0;
	last_cost = UINT_MAX;
	if (dfs(f, f->start, f->end, FIRST) == FAILURE)
		return (ft_dprintf(STDERR_FILENO, E_MAP));
	reset_info(f);
	while (dfs(f, f->start, f->end, type) == SUCCESS)
	{
		orient_path_to(f, f->end, REV_NO);
		curr_cost = get_cost(f);
		if (curr_cost > last_cost)
		{
			orient_path_to(f, f->end, REV_YES);
			break ;
		}
		last_cost = curr_cost;
		reset_info(f);
	}
	return (resolve_nontrivial_helper(f));
}

int				resolve(t_farm *f)
{
	unsigned	status;

	if (start_links_end(f) == SUCCESS)
		return (resolve_trivial(f));
	else
	{
		status = resolve_nontrivial(f, FULL);
		if (status == FAILURE)
		{
			reset_all(f);
			return (resolve_nontrivial(f, SIMPLE));
		}
		return ((status != SUCCESS) ? FAILURE : SUCCESS);
	}
}
