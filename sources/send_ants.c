/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 17:33:06 by amalsago          #+#    #+#             */
/*   Updated: 2020/05/23 15:56:51 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "lib.h"
#include "colors.h"

#include <unistd.h>

static void			move_ant(t_room *prev, t_room *curr, unsigned k)
{
	static unsigned	ant_id = 0;

	if (curr == START && g_farm.ants_start > 0)
	{
		if (g_farm.ants_start > 0 && g_farm.ants_by_path[k] > 0)
		{
			ant_id += 1;
			g_farm.ants_start -= 1;
			g_farm.ants_by_path[k] -= 1;
			curr->ant_id = ant_id;
		}
		else
			curr->ant_id = 0;
	}
	prev->ant_id = curr->ant_id;
	curr->ant_id = 0;
	if (prev->ant_id != 0)
	{
		if (prev == END)
		{
			g_farm.ants_end += 1;
			/* ft_printf(SGR_FG_GREEN"L%d-%s "SGR_NORMAL, prev->ant_id, prev->name); */
			ft_printf("L%d-%s ", prev->ant_id, prev->name);
		}
		else
			ft_printf("L%d-%s ", prev->ant_id, prev->name);
	}
}

static void			send_ants_helper(t_room *prev, t_room *curr, unsigned k)
{
	unsigned		j;

	j = -1;
	move_ant(prev, curr, k);
	while (++j < curr->LINK_LEN)
		if (curr->link.dir[j] == ALLOWED)
		{
			prev = curr;
			curr = ROOMS + curr->link.arr[j];
			move_ant(prev, curr, k);
			j = -1;
		}
}

static void			send_onemove(void)
{
	ft_printf(SGR_BOLD SGR_FG_YELLOW"%-5d"SGR_NORMAL, 1);
	while (g_farm.ants_end != g_farm.ants_total)
		move_ant(END, START, 0);
	ft_printf("\n");
}

void				sort_paths_len_graph(void)
{
	t_byte			sorted;
	unsigned		i;
	unsigned		j;

	sorted = 0;
	while (!sorted)
	{
		i = -1;
		sorted = 1;
		while (++i < END->LINK_LEN - 1)
			if (END->link.dir[i] == ALLOWED)
			{
				j = i;
				while (++j < END->LINK_LEN - 1)
					if (END->link.dir[j] == ALLOWED)
						break ;
				if ((ROOMS + END->link.arr[i])->cost[CUR]
					> (ROOMS + END->link.arr[j])->cost[CUR])
				{
					ft_swap_xor(&END->link.arr[i], &END->link.arr[j]);
					sorted = 0;
				}
			}
	}
}

void				send_ants(void)
{
	unsigned		i;
	unsigned		k;
	unsigned		moves;

	i = -1;
	moves = 0;
	(start_links_end() == SUCCESS) ? send_onemove() : 0;
	sort_paths_len_graph();
	while (g_farm.ants_end != g_farm.ants_total)
	{
		i = -1;
		k = -1;
		moves += 1;
		ft_printf(SGR_BOLD SGR_FG_YELLOW"%-5d"SGR_NORMAL, moves);
		while (g_farm.ants_end != g_farm.ants_total && ++i < END->LINK_LEN)
			if (END->link.dir[i] == ALLOWED)
				send_ants_helper(END, ROOMS + END->link.arr[i], ++k);
		ft_printf("\n");
	}
}
