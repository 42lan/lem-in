/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 11:44:35 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/21 17:25:03 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "lemin.h"

static void		hmap_collision_handler(t_hmap *hmap, t_room *room)
{
	t_hmap		*new;
	t_hmap		*tmp;

	tmp = hmap;
	new = (t_hmap *)ft_memalloc(sizeof(t_hmap));
	new->room = room;
	new->next = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void			hmap_add(t_hmap *hmap, t_room *room)
{
	int			index;

	index = hmap_index(room->name);
	if (hmap[index].room == NULL)
		hmap[index].room = room;
	else
		hmap_collision_handler(&hmap[index], room);
}
