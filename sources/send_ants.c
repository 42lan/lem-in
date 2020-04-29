/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 17:33:06 by amalsago          #+#    #+#             */
/*   Updated: 2020/04/28 17:35:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	move_ant_forward(unsigned ant, t_room *room)
{
	if (room == END)
		g_farm.ants_end += 1;
	room->ant_id = ant;
	/* ft_printf("%s received #%u\n", room->name, room->ant_id); */
	ft_printf("L%d-%s ", room->ant_id, room->name);
}

void	send_ants(void)
{
	unsigned	i;
	unsigned	ant;

	ant = 0;
	while (g_farm.ants_end <= g_farm.ants_total)
	{
		if (g_farm.ants_start == 0)
		{
			ft_printf("No ants left in start room\n");
		}
		i = -1;
		while (++i < g_farm.size) // Loop through all rooms
		{
			if (&ROOMS[i] == START && g_farm.ants_start > 0)
			{
				ant += 1;
				ROOMS[i].ant_id = ant;
				g_farm.ants_start--;
			}
			if (ROOMS[i].flags != F_DEAD && ROOMS[i].flags != F_END) // Move ants between only non-dead rooms
			{
				/* ft_printf("%s have ants #%u\n", ROOMS[i].name, ROOMS[i].ant_id); */
				move_ant_forward(ROOMS[i].ant_id, &ROOMS[i + 1]);
				ROOMS[i].ant_id = 0;
			}
			ft_printf("\n");
		}
	}
}
