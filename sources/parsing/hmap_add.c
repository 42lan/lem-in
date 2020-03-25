/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 11:44:35 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/25 15:19:49 by abaisago         ###   ########.fr       */
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

int			hmap_index(const char *key)
{
	size_t		i;
	uint32_t	hash;

	hash = 0;
	i = -1;
	while (key[++i] != '\0')
		hash = 33 * (hash ^ key[i]);
	return (hash % HMAP_SIZE);
}

void			hmap_add(t_hmap *hmap, t_room *room)
{
	int			index;
	t_room		*room_alloc;

	room_alloc = (t_room *)malloc(sizeof(*room));
	ft_memcpy(room_alloc, room, sizeof(t_room));
	index = hmap_index(room_alloc->name);
	if (hmap[index].room == NULL)
		hmap[index].room = room_alloc;
	else
		hmap_collision_handler(&hmap[index], room_alloc);
}
