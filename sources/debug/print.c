/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 16:10:47 by abaisago          #+#    #+#             */
/*   Updated: 2020/04/03 10:45:44 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "libft.h"

#include "parsing.h"
#include "lemin.h"

int		dbg_print_room(void *content, size_t size, unsigned pos, unsigned max)
{
	t_room	*room;
	int		ret;

	room = content;
	ret = ft_printf("=%u: [%-5s %d,%d]", room->index, room->name,
		room->coord.x, room->coord.y);
	if (room->link_list != NULL)
		ret += ft_printf("(%d) \n", room->nlinks);
	else if (pos == max)
		ret += ft_printf("\n");
	return (ret);
}

void	dbg_hmap_print(t_list *hmap)
{
	int				i;

	i = -1;
	while (++i < HMAP_SIZE)
		if (hmap[i].head != NULL)
		{
			ft_printf("%4d: ", i);
			ft_list_print(&hmap[i], dbg_print_room);
		}
}

void	dbg_farm_print(t_farm *farm)
{
	unsigned	i;
	unsigned	j;
	t_room		*room;

	ft_printf("Number of ants: %d\n", farm->ants);
	i = -1;
	while (++i < farm->size)
	{
		room = &farm->rooms[i];
		ft_printf("%04u: #%05u [%-5s %04d,%04d] (%u) > ", hmap_index(room->name),
			room->index, room->name, room->coord.x, room->coord.y, room->nlinks);
		j = -1;
		while (++j < room->nlinks - 1)
			ft_printf("%-5s > ", farm->rooms[room->links[j]].name);
		ft_printf("%-5s", farm->rooms[room->links[j]].name);
		ft_putchar('\n');
	}
}

