/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:17:30 by abosch            #+#    #+#             */
/*   Updated: 2020/04/21 19:02:08 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "del.h"
#include "lemin.h"

#include <stdlib.h>

void	del_link_list(void *content, size_t size)
{
	t_list	*list;

	list = (t_list*)content;
	ft_memdel((void**)&list);
}

void	del_link(void *content, size_t size)
{
	t_link *link;

	link = (t_link*)content;
	ft_list_del(&link->list, &del_link_list);
	ft_memdel((void**)&link->arr);
	ft_memdel((void**)&link->dir);
	/* free(&room->link); */
}

void	del_room(void *content)
{
	t_room *room;

	room = (t_room*)content;
	room->index = 0;
	ft_strdel(&room->name);
	ft_bzero(&room->coord, sizeof(t_ivec2));
	del_link(&room->link, 0);
	ft_bzero(&room->flags, sizeof(t_byte));
	ft_bzero(&room->cost, sizeof(unsigned*));
	ft_bzero(&room->pre, sizeof(unsigned*));
	room->ant_id = 0;
	/* free(&room); */
}


void	final_free(void)
{
	unsigned	i;

	i = 0;
	while (i < g_farm.size)
		del_room(&ROOMS[i++]);
	free(ROOMS);
}
