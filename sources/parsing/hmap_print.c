/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 12:55:47 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/25 19:57:51 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void			room_print(t_room *room)
{
	ft_printf("[%s ", room->name);
	ft_printf("%d,%d] ", room->coord.x, room->coord.y);
}

void				hmap_print(t_list *hmap)
{
	int				i;
	size_t			j;
	t_list_link		*tmp;

	i = -1;
	while (++i < HMAP_SIZE)
	{
		j = 0;
		if (hmap[i].head != NULL)
		{
			ft_printf("%d: ", i);
			room_print(hmap[i].head->content);
			if (hmap[i].head->next != NULL)
			{
				tmp = hmap[i].head->next;
				while (j++ < hmap[i].size - 1)
				{
					room_print(tmp->content);
					tmp = tmp->next;
				}
			}
			ft_putchar('\n');
		}
	}
}
