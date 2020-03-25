/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 12:55:47 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/25 18:49:19 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void		room_print(t_room *room)
{
	ft_printf("[%s ", room->name);
	ft_printf("%d,%d]", room->coord.x, room->coord.y);
}

void			hmap_print(t_hmap *hmap)
{
	int			i;
	t_hmap		*tmp;

	i = -1;
	while (++i < HMAP_SIZE)
	{
		if (hmap[i].room != NULL)
		{
			ft_printf("%d: ", i);
			room_print(hmap[i].room);
			if (hmap[i].next != NULL)
			{
				tmp = hmap[i].next;
				while (tmp)
				{
					room_print(tmp->room);
					tmp = tmp->next;
				}
			}
			ft_putchar('\n');
		}
	}
}
