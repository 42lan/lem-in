/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 11:44:35 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/25 19:46:00 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "lemin.h"

#include <errno.h>
#include <stddef.h>
#include <string.h>

/*
static void			hmap_collision_handler(t_list *hmap, t_room *room)
{
	t_list_link		*link;

	while (link->next)
		link = link->next;
	tmp->next = new;
	ft_list_push(&hmap[index], ft_list_link_new(room, sizeof(*room)));
	//ft_list_push_front(&hmap[index], ft_list_link_new(room, sizeof(*room)));
}
*/

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

void			hmap_add(t_list *hmap, t_room *room)
{
	int			index;

	index = hmap_index(room->name);
	//if (hmap[index].head == NULL)
		ft_list_push_front(&hmap[index], ft_list_link_new(room, sizeof(*room)));
	/*
	else
		hmap_collision_handler(&hmap[index], room);
	*/
}
