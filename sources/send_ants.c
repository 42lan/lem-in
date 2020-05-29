/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 17:33:06 by amalsago          #+#    #+#             */
/*   Updated: 2020/05/29 13:18:13 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "lib.h"
#include "colors.h"
#include "algo.h"
#include "debug.h"

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
			g_farm.ants_end += 1;
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
	/* ft_printf(SGR_BOLD SGR_FG_YELLOW"%-5d"SGR_NORMAL, 1); */
	while (g_farm.ants_end != g_farm.ants_total)
		move_ant(END, START, 0);
	ft_printf("\n");
}

static void         spot_no_path(void)
{
    unsigned        i;

    i = -1;
    while (++i < END->LINK_LEN) 
        if (END->link.dir[i] != ALLOWED)
            (ROOMS + END->link.arr[i])->cost[CUR] = -1;
}

void                sort_paths_len_graph(void)
{
    unsigned        i;
    unsigned        len;
    t_byte          swapped;
    unsigned        tmp;

    spot_no_path();
    swapped = 1;
    len = END->LINK_LEN;
    while (swapped)
    {
        swapped = 0;
        i = -1;
        while (++i < len - 1)
        {
            if((ROOMS + END->link.arr[i])->cost[CUR] > (ROOMS + END->link.arr[i + 1])->cost[CUR])
            {
                tmp = END->link.arr[i];
                END->link.arr[i] = END->link.arr[i + 1];
                END->link.arr[i + 1] = tmp;
                swapped = 1;
            }
        }
        len--;
    }
    if (DEBUGP)
    {   
        i = -1;
        while (++i < END->LINK_LEN)
        {
            ft_printf("%s : %u |", (ROOMS + END->link.arr[i])->name, (ROOMS + END->link.arr[i])->cost[CUR]);
            ft_printf("\n");
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
	if (start_links_end() == SUCCESS)
		send_onemove();
	else
	{
		improve_paths();
		sort_paths_len_graph();
		while (g_farm.ants_end != g_farm.ants_total)
		{
			i = -1;
			k = -1;
			moves += 1;
			/* ft_printf(SGR_BOLD SGR_FG_YELLOW"%-5d"SGR_NORMAL, moves); */
			while (g_farm.ants_end != g_farm.ants_total && ++i < g_farm.nb_paths)
				send_ants_helper(END, ROOMS + END->link.arr[i], ++k);
			/* if (moves == 2) */
			/* 	return; */
			ft_printf("\n");
		}
	}
}
