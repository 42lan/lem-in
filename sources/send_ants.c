/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 17:33:06 by amalsago          #+#    #+#             */
/*   Updated: 2020/05/19 20:08:14 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "colors.h"

#include <unistd.h>
static void		move_ant(t_room *prev, t_room *curr)
{
	static unsigned	ant_id = 0;

	if (curr == START && g_farm.ants_start > 0)
	{
		if (g_farm.ants_start > 0)
			ant_id += 1;
		else
			ant_id = 0;
		g_farm.ants_start -= 1;
		curr->ant_id = ant_id;
	}
	prev->ant_id = curr->ant_id;
	curr->ant_id = 0;
	if (prev->ant_id != 0)
	{
		if (prev == END)
		{
			g_farm.ants_end += 1;
//			ft_printf(SGR_FG_RED"L%d-%s "SGR_NORMAL, prev->ant_id, prev->name);
			ft_printf("L%d-%s ", prev->ant_id, prev->name);
		}
		else
			ft_printf("L%d-%s ", prev->ant_id, prev->name);
	}
}

static void		send_ants_helper(t_room *prev, t_room *curr)
{
	unsigned	j;

	j = -1;
	move_ant(prev, curr);
	while (++j < curr->LINK_LEN)
	{
		if (curr->link.dir[j] == ALLOWED)
		{
			prev = curr;
			curr = ROOMS + curr->link.arr[j];
			move_ant(prev, curr);
			j = -1;
		}
	}
}

static unsigned		start_end_connected(void)
{
	unsigned		i;

	i = -1;

static void			one_move(void)
{
	ft_printf(SGR_BOLD SGR_FG_YELLOW"%-5d"SGR_NORMAL, 1);
	while (g_farm.ants_end != g_farm.ants_total)
		move_ant(END, START, 0);
	ft_printf("\n");
}

	moves = 0;
	if (start_end_connected() == SUCCESS)
		one_move();
	while (g_farm.ants_end != g_farm.ants_total)
	{
		while (g_farm.ants_end != g_farm.ants_total && ++i < END->LINK_LEN)
			if (END->link.dir[i] == ALLOWED)
				send_ants_helper(END, ROOMS + END->link.arr[i]);
		ft_putchar('\n');
		moves += 1;
		i = -1;
	}
//	ft_printf(SGR_INVERSE" Total moves: %d \n"SGR_NORMAL, moves);
}
