/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 03:15:37 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/03 05:00:29 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		type_of_dir(t_byte dir)
{
	if (dir == DUPLEX)
		ft_printf("DUPLEX\n");
	else if (dir == BLOCKED)
		ft_printf("BLOCKED\n");
	else if (dir == ALLOWED)
		ft_printf("ALLOWED\n");
	else
		ft_printf("NO ORIENTATION\n");
}

void			show_orien_name(const char *name)
{
	unsigned	i;
	unsigned	j;
	t_room		*room;

	i = 0;
	j = -1;
	ft_printf("~~~~~~~ Orientation de la piece par nom %s ~~~~~~~\n", name);
	while (++j < g_farm.size)
	{
		room = &g_farm.rooms[i];
		if (ft_strequ(room->name, name))
			while (++i < LINK_SIZE)
			{
				ft_printf("%s - ", ROOMS[LINK_ARR[i]].name);
				type_of_dir(LINK_DIR[i]);
			}
	}
	ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void			show_orien(t_room *room)
{
	unsigned	i;

	i = -1;
	ft_printf("~~~~~~~ Orientation de la piece %s ~~~~~~~\n", room->name);
	while (++i < LINK_SIZE)
	{
		ft_printf("%s - ", ROOMS[LINK_ARR[i]].name);
		type_of_dir(LINK_DIR[i]);
	}
	ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void			print_map_cost(void)
{
	unsigned	i;

	i = -1;
	while (++i < g_farm.size)
		ft_printf("%-7s pre: %3u/%-10u | cost: %3u/%-10u\n", ROOMS[i].name,
				ROOMS[i].pre[CUR], ROOMS[i].pre[OLD],
				ROOMS[i].cost[CUR], ROOMS[i].cost[OLD]);
}

void			print_cost(void)
{
	unsigned	i;

	i = -1;
	while (++i < END->LINK_LEN)
		ft_printf("{fred}%s cost %d{}\n", (ROOMS + END->link.arr[i])->name,
			(ROOMS + END->link.arr[i])->cost[CUR]);
}
