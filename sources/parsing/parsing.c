/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 09:32:10 by amalsago          #+#    #+#             */
/*   Updated: 2020/04/05 16:12:48 by abaisago         ###   ########.fr       */
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

void		links_to_array(t_room *rooms, unsigned size)
{
	unsigned	i;

	i = -1;
	while (++i < size)
	{
		if ((rooms[i].link.arr = (unsigned*)ft_list_to_arr(rooms[i].link.list,
			sizeof (unsigned), NULL)) == NULL)
			ft_printerr("lem-in: links_to_array(arr malloc): %s\n",
				strerror(errno));
		if ((rooms[i].link.dir =
			(t_byte*)malloc(rooms[i].link.list->len)) == NULL)
			ft_printerr("lem-in: links_to_array(dir malloc): %s\n",
				strerror(errno));
	}
}

int			parse_input(t_farm *farm, t_list *hmap)
{
	t_list	*room_list; //TODO Needs to be freed

	farm->ants = get_ants();
	room_list = get_room_list(farm, hmap);
	// TODO: Needs to be freed
	if ((farm->rooms = (t_room*)ft_list_to_arr(room_list,
		sizeof (t_room), NULL)) == NULL)
		ft_printerr("lem-in: get_rooms(list_to_arr): %s\n", strerror(errno));
	farm->size = room_list->len;
	links_to_array(farm->rooms, farm->size);
	dbg_farm_print(farm);
	return (SUCCESS);
}
