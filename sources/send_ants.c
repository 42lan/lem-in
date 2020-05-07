/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 17:33:06 by amalsago          #+#    #+#             */
/*   Updated: 2020/05/07 19:09:13 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	move_ant(t_room *prev, t_room *curr)
{
	prev->ant_id = curr->ant_id;
	if (prev->ant_id != 0)
		ft_printf("L%d-%s ", prev->ant_id, prev->name);
}

void	send_ants(void)
{
	unsigned	i;
	unsigned	j;
	unsigned	ant_id;
	t_room		*curr;
	t_room		*prev;

	i = -1;
	ant_id = 0;
	while (g_farm.ants_end != g_farm.ants_total)
	{
		while (++i < END->LINK_LEN && g_farm.ants_end != g_farm.ants_total)
			if (END->link.dir[i] == ALLOWED)
			{
				j = -1;
				prev = END;
				curr = ROOMS + END->link.arr[i];
				move_ant(prev, curr);
				if (prev == END)
					if (prev->ant_id != 0)
						g_farm.ants_end += 1;
				while (++j < curr->LINK_LEN)
					if (curr->link.dir[j] == ALLOWED)
					{
						prev = curr;
						curr = ROOMS + curr->link.arr[j];
						if (curr == START && g_farm.ants_start > 0)
						{
							ant_id += 1;
							g_farm.ants_start -= 1;
							curr->ant_id = ant_id;
						}
						move_ant(prev, curr);
						j = -1;
					}
			}
		ft_putchar('\n');
		i = -1;
	}
}
