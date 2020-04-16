/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 14:47:17 by abosch            #+#    #+#             */
/*   Updated: 2020/04/16 17:56:39 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	debug_deadend(void)
{
	int	i;

	i = -1;
	while ((unsigned)++i < g_farm.size)
	{
		if (ROOMS[i].flags & F_DEAD)
			ft_printf("%s is dead\n", ROOMS[i].name);
		else
			ft_printf("%s is alive\n", ROOMS[i].name);
	}
}

void	remove_deadend(void)
{
	int		i;
	int		j;
	int		k;
	t_room	*room;
	t_byte	con;

	con = 1;
	debug_deadend();
	while (con)
	{
		i = -1;
		con = 0;
		while ((unsigned)++i < g_farm.size)
		{
			j = -1;
			room = &ROOMS[i];
			k = 0;
			if (room != START && room != END)
			{
				while ((unsigned)++j < room->LINK_LEN)
					if (!(ROOMS[LINK_ARR[j]].flags & F_DEAD))
						k++;
				if (k < 2)
				{
					room->flags |= F_DEAD;
					con = 1;
				}
			}
		}
	}
	debug_deadend();
}
