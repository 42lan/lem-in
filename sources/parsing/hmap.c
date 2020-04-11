/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 11:44:35 by amalsago          #+#    #+#             */
/*   Updated: 2020/04/10 14:04:13 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "lemin.h"

#include "tools.h"

#include <errno.h>
#include <stddef.h>
#include <string.h>

void		hmap_init(t_list *hmap)
{
	int		i;

	i = -1;
	while (++i < HMAP_SIZE)
	{
		hmap[i].head = NULL;
		hmap[i].len = 0;
		hmap[i].size = 0;
	}
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

int			hmap_add(t_list *hmap, t_room *room)
{
	int			index;

	index = hmap_index(room->name);
	if (ft_list_find(&hmap[index], room->name, room_namecmp))
		return (FAILURE);
	ft_list_push_front(&hmap[index], ft_list_link_new(room, sizeof(*room)));
	return (SUCCESS);
}
