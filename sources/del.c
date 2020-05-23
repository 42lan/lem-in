/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:17:30 by abosch            #+#    #+#             */
/*   Updated: 2020/05/24 16:34:35 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "del.h"
#include "lemin.h"
#include "parsing.h"

#include <stdlib.h>

void	del_link_list(void *content, size_t size)
{
	(void)content;
	(void)size;
}

void	del_link(void *content, size_t size)
{
	t_link *link;

	link = (t_link*)content;
	ft_list_del(&link->list, &del_link_list);
	ft_memdel((void**)&link->arr);
	ft_memdel((void**)&link->dir);
}

void	del_room(void *content, size_t size)
{
	t_room *room;

	room = (t_room*)content;
	ft_strdel(&room->name);
	del_link(&room->link, 0);
}


void	final_free(t_list *hmap)
{
	unsigned	i;

	i = 0;
	while (i < g_farm.size)
	{
		del_room(g_farm.rooms + i++, sizeof(t_room*));
		ft_bzero(g_farm.rooms + i, sizeof(t_room*));
	}
	free(g_farm.rooms);
	free(g_farm.ants_by_path);
	i = 0;
	while (i < HMAP_SIZE)
	{
		if (hmap[i].head != NULL)
			ft_list_clear(hmap + i, &del_link_list);
		i++;
	}
}
