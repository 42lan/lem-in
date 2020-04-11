/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 16:10:47 by abaisago          #+#    #+#             */
/*   Updated: 2020/04/10 16:07:35 by abaisago         ###   ########.fr       */
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
	ret += ft_printf("(%d) \n", room->link.list->size);
	if (pos == max)
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

	ft_printf("Total number of ants: %d\n", farm->ants_total);
	ft_printf("start: %s\n", farm->start->name);
	ft_printf("end: %s\n", farm->end->name);;
	i = -1;
	while (++i < farm->size)
	{
		room = &farm->rooms[i];
		ft_printf("%04u: #%05u [%-5s %04d,%04d] (%u) > ", hmap_index(room->name),
			room->index, room->name, room->coord.x, room->coord.y,
			room->link.list->len);
		j = -1;
		while (++j < room->link.list->len)
			ft_printf(room->link.arr[j + 1] ? "%-5s > " : "%-5s",
				farm->rooms[room->link.arr[j]].name);
		ft_putchar('\n');
	}
}
