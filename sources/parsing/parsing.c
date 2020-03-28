/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 09:32:10 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/28 17:35:09 by abaisago         ###   ########.fr       */
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
#include <string.h>

int			parse_input(t_farm *farm, t_list *hmap)
{
	t_list	*room_list;

	farm->ants = get_ants();
	room_list = get_room_list(hmap);
	// TODO: Needs to be freed
	if ((farm->rooms = (t_room**)ft_list_to_arr(room_list, room_index)) == NULL)
		ft_printerr("lem-in: get_rooms(list_to_arr): %s\n", strerror(errno));
	farm->size = room_list->size;
	/* links_to_array(farm); */
	hmap_print(hmap);
	return (SUCCESS);
}
