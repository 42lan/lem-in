/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 09:32:10 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/03 07:13:45 by amalsago         ###   ########.fr       */
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

static int		links_to_array(t_farm *f, t_room *rooms, unsigned size)
{
	unsigned	i;

	i = -1;
	while (++i < size)
	{
		if (!(rooms[i].lnk.arr = (unsigned*)ft_list_to_arr(rooms[i].lnk.lst,
			sizeof(unsigned), NULL)))
			return (ft_dprintf(STDERR_FILENO, "lem-in: link.arr malloc\n"));
		if (!(rooms[i].lnk.dir = (t_byte*)ft_memalloc(rooms[i].lnk.lst->len)))
			return (ft_dprintf(STDERR_FILENO, "lem-in: link.dir malloc\n"));
		if (rooms[i].flags & F_START)
			f->start = rooms + i;
		if (rooms[i].flags & F_END)
			f->end = rooms + i;
	}
	return (SUCCESS);
}

int				parse_input(t_farm *f, t_list *hmap)
{
	t_list		*room_list;

	f->ants_total = get_ants();
	f->ants_start = f->ants_total;
	f->ants_end = 0;
	room_list = get_room_list(hmap);
	if ((f->rooms = (t_room*)ft_list_to_arr(room_list,
		sizeof(t_room), NULL)) == NULL)
		return (ft_dprintf(STDERR_FILENO, "lem-in: get_rooms(list_to_arr)\n"));
	f->size = room_list->len;
	if (links_to_array(f, f->rooms, f->size) != SUCCESS)
		return (FAILURE);
	ft_list_del(&room_list, &del_link_list);
	if (!f->start || !f->end)
		return (ft_dprintf(STDERR_FILENO, E_SE_DEF));
	if (!f->start->lnk.lst->len || !f->end->lnk.lst->len)
		return (ft_dprintf(STDERR_FILENO, E_SE_LINK));
	remove_deadend(f);
	return (SUCCESS);
}
