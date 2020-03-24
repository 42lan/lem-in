/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 12:55:47 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/24 18:01:47 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void		room_print(t_room *room)
{
	ft_printf("[%s ", room->name);
	ft_printf("%d %d] ", room->coord.x, room->coord.y);
}

void			hmap_print(t_hmap *hmap)
{
	int			i;
	t_hmap		*tmp;

	i = -1;
	while (++i < HMAP_SIZE)
	{
		ft_printf("%d: ", i);
		if (hmap[i].room != NULL)
		{
			room_print(hmap[i].room);
			if (hmap[i].next != NULL)
			{
				tmp = &hmap[i];
				while (tmp->next)
				{
					room_print(hmap[i].room);
					tmp = tmp->next;
				}
			}
		}
		ft_putchar('\n');
	}
}
