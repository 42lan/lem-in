/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 09:32:10 by amalsago          #+#    #+#             */
/*   Updated: 2020/05/23 12:18:52 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

#include "debug.h"
#include "lemin.h"
#include "predicates.h"
#include "tools.h"

#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static void		links_to_array(t_room *rooms, unsigned size)
{
	unsigned	i;

	i = -1;
	while (++i < size)
	{
		if (!(rooms[i].link.arr = (unsigned*)ft_list_to_arr(rooms[i].link.list,
			sizeof(unsigned), NULL)))
			ft_printerr("lem-in: links_to_array(arr malloc): %s\n",
				strerror(errno));
		if (!(rooms[i].link.dir = (t_byte*)ft_memalloc(rooms[i].LINK_LEN)))
			ft_printerr("lem-in: links_to_array(dir malloc): %s\n",
				strerror(errno));
		if (rooms[i].flags & F_START)
			g_farm.start = rooms + i;
		if (rooms[i].flags & F_END)
			g_farm.end = rooms + i;
	}
}

int			parse_input(t_list *hmap)
{
	t_list	*room_list; //TODO Needs to be freed

	if ((g_farm.ants_total = get_ants()) == 0)
		ft_printerr(E_NOANT);
	g_farm.ants_start = g_farm.ants_total;
	g_farm.ants_end = 0;
	room_list = get_room_list(hmap);
	// TODO: Needs to be freed
	if ((g_farm.rooms = (t_room*)ft_list_to_arr(room_list,
		sizeof (t_room), NULL)) == NULL)
		ft_printerr("lem-in: get_rooms(list_to_arr): %s\n", strerror(errno));
	g_farm.size = room_list->len;
	links_to_array(g_farm.rooms, g_farm.size);
	if (!g_farm.start || !g_farm.end)
		ft_printerr(E_SE_DEF);
	if (!g_farm.start->link.list->len || !g_farm.end->link.list->len)
		ft_printerr(E_SE_LINK);
	return (SUCCESS);
}
