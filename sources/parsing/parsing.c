/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 09:32:10 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/03 02:57:47 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

#include "debug.h"
#include "lemin.h"
#include "tools.h"
#include "del.h"

#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int		links_to_array(t_room *rooms, unsigned size)
{
	unsigned	i;

	i = -1;
	while (++i < size)
	{
		if (!(rooms[i].link.arr = (unsigned*)ft_list_to_arr(rooms[i].link.list,
			sizeof(unsigned), NULL)))
			return (ft_dprintf(STDERR_FILENO, "lem-in: link.arr malloc\n"));
		if (!(rooms[i].link.dir = (t_byte*)ft_memalloc(rooms[i].LINK_LEN)))
			return (ft_dprintf(STDERR_FILENO, "lem-in: link.dir malloc\n"));
		if (rooms[i].flags & F_START)
			g_farm.start = rooms + i;
		if (rooms[i].flags & F_END)
			g_farm.end = rooms + i;
	}
	return (SUCCESS);
}

int				parse_input(t_list *hmap)
{
	t_list		*room_list;

	g_farm.ants_total = get_ants();
	g_farm.ants_start = g_farm.ants_total;
	g_farm.ants_end = 0;
	room_list = get_room_list(hmap);
	if ((g_farm.rooms = (t_room*)ft_list_to_arr(room_list,
		sizeof (t_room), NULL)) == NULL)
		return (ft_dprintf(STDERR_FILENO, "lem-in: get_rooms(list_to_arr)\n"));
	g_farm.size = room_list->len;
	if (links_to_array(g_farm.rooms, g_farm.size) != SUCCESS)
		return (FAILURE);
	ft_list_del(&room_list, &del_link_list);
	if (!g_farm.start || !g_farm.end)
		return (ft_dprintf(STDERR_FILENO, E_SE_DEF));
	if (!g_farm.start->link.list->len || !g_farm.end->link.list->len)
		return (ft_dprintf(STDERR_FILENO, E_SE_LINK));
	remove_deadend();
	return (SUCCESS);
}
