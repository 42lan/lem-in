/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 13:12:51 by amalsago          #+#    #+#             */
/*   Updated: 2020/05/29 22:58:37 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "debug.h"

void	print_state(void)
{
	unsigned j=-1;
	while (++j < END->LINK_LEN)
		if (END->link.dir[j] == ALLOWED)
			ft_printf("room %s, costs %d\n", (ROOMS + END->link.arr[j])->name, (ROOMS+END->link.arr[j])->cost[CUR]);
}

void	print_ant_by_path(void)
{
	ft_printf("\n-----------------------\n");
	unsigned i = -1;
	unsigned total = 0;
	while (++i < g_farm.nb_paths)
	{
		ft_printf("%d %d\n", i, g_farm.ants_by_path[i]);
		total += g_farm.ants_by_path[i];
	}
	ft_printf("TOTAL %d\n", total);
	ft_printf("-----------------------\n");
}

void		print_from_start2end(void)
{
	unsigned i = -1;
	unsigned j = -1;
	t_room *room;

	while (++i < START->LINK_LEN)
	{
		if (START->link.dir[i] == BLOCKED)
		{
			/* ft_printf("{fred}%s - %s (%d) {}", START->name, (ROOMS+START->link.arr[i])->name, g_farm.ants_by_path[++k]); */
			ft_printf("{fred}%s{} ", START->name);
			room = ROOMS + START->link.arr[i];
			j = -1;
			while (++j < LINK_SIZE)
				if (LINK_DIR[j] == BLOCKED)
				{
					if (ROOMS + LINK_ARR[j] == END)
						ft_printf("{fred}%s{}\n", room->name);
					else
						ft_printf("%s ", room->name);
					room = ROOMS + LINK_ARR[j];
					j = -1;
				}
		}
	}
}
