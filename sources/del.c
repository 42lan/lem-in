/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:17:30 by abosch            #+#    #+#             */
/*   Updated: 2020/06/03 06:47:25 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "del.h"
#include "lemin.h"
#include "parsing.h"

#include <stdlib.h>

void			del_link_list(void *content, size_t size)
{
	(void)content;
	(void)size;
}

void			del_link(void *content, size_t size)
{
	t_link		*link;

	link = (t_link*)content;
	ft_list_del(&link->lst, &del_link_list);
	ft_memdel((void**)&link->arr);
	ft_memdel((void**)&link->dir);
}

static void		del_room(void *content, size_t size)
{
	t_room		*room;

	room = (t_room*)content;
	ft_strdel(&room->name);
	del_link(&room->lnk, 0);
}

static void		free_hmap(t_list *hmap)
{
	unsigned	i;

	i = -1;
	while (++i < HMAP_SIZE)
		if (hmap[i].head != NULL)
			ft_list_clear(hmap + i, &del_link_list);
}

void			final_free(t_farm *f, t_list *hmap)
{
	unsigned	i;

	i = 0;
	while (i < f->size)
	{
		del_room(f->rooms + i++, sizeof(t_room*));
		ft_bzero(f->rooms + i, sizeof(t_room*));
	}
	free(f->rooms);
	free(f->ants_by_path);
	free_hmap(hmap);
}
