/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 17:33:06 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/03 10:33:56 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "colors.h"
#include "algo.h"
#include "debug.h"

#include <unistd.h>

static void			move_ant(t_farm *f, t_room *prev, t_room *curr, unsigned k)
{
	static unsigned	ant_id = 0;

	if (curr == f->start && f->ants_start > 0)
	{
		if (f->ants_start > 0 && f->ants_by_path[k] > 0)
		{
			ant_id += 1;
			f->ants_start -= 1;
			f->ants_by_path[k] -= 1;
			curr->ant_id = ant_id;
		}
		else
			curr->ant_id = 0;
	}
	prev->ant_id = curr->ant_id;
	curr->ant_id = 0;
	if (prev->ant_id != 0)
	{
		if (prev == f->end)
			f->ants_end += 1;
		ft_printf("L%d-%s ", prev->ant_id, prev->name);
	}
}

static void			send_ants_helper(t_farm *f, t_room *prev, t_room *curr,
						unsigned k)
{
	unsigned		j;

	j = -1;
	move_ant(f, prev, curr, k);
	while (++j < curr->lnk.lst->len)
		if (curr->lnk.dir[j] == ALLOWED)
		{
			prev = curr;
			curr = f->rooms + curr->lnk.arr[j];
			move_ant(f, prev, curr, k);
			j = -1;
		}
}

static void			send_onemove(t_farm *f)
{
	ft_printf(SGR_BOLD SGR_FG_YELLOW"%-5d"SGR_NORMAL, 1);
	while (f->ants_end != f->ants_total)
		move_ant(f, f->end, f->start, 0);
	ft_printf("\n");
}

void				send_ants(t_farm *f)
{
	unsigned		i;
	unsigned		k;
	unsigned		moves;

	i = -1;
	moves = 0;
	if (start_links_end(f) == SUCCESS)
		send_onemove(f);
	while (f->ants_end != f->ants_total)
	{
		i = -1;
		k = -1;
		moves += 1;
		ft_printf(SGR_BOLD SGR_FG_YELLOW"%-5d"SGR_NORMAL, moves);
		while (f->ants_end != f->ants_total && ++i < f->end->lnk.lst->len)
			if (f->end->lnk.dir[i] == ALLOWED)
				send_ants_helper(f, f->end, f->rooms + f->end->lnk.arr[i], ++k);
		ft_printf("\b \b\n");
	}
}
