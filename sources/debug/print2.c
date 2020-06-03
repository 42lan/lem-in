/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 03:15:37 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/03 06:45:33 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		type_of_dir(t_byte dir)
{
	if (dir == DUPLEX)
		ft_printf("DUPLEX\n");
	else if (dir == BLOCKED)
		ft_printf("BLOCKED\n");
	else if (dir == ALLOWED)
		ft_printf("ALLOWED\n");
	else
		ft_printf("NO ORIENTATION\n");
}

void			show_orien_name(t_farm *f, const char *name)
{
	unsigned	i;
	unsigned	j;
	t_room		*room;

	i = 0;
	j = -1;
	ft_printf("~~~~~~~ Orientation de la piece par nom %s ~~~~~~~\n", name);
	while (++j < f->size)
	{
		room = &f->rooms[i];
		if (ft_strequ(room->name, name))
			while (++i < room->lnk.lst->len)
			{
				ft_printf("%s - ", f->rooms[room->lnk.arr[i]].name);
				type_of_dir(room->lnk.dir[i]);
			}
	}
	ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void			show_orien(t_farm *f, t_room *room)
{
	unsigned	i;

	i = -1;
	ft_printf("~~~~~~~ Orientation de la piece %s ~~~~~~~\n", room->name);
	while (++i < room->lnk.lst->len)
	{
		ft_printf("%s - ", f->rooms[room->lnk.arr[i]].name);
		type_of_dir(room->lnk.dir[i]);
	}
	ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void			print_map_cost(t_farm *f)
{
	unsigned	i;

	i = -1;
	while (++i < f->size)
		ft_printf("%-7s pre: %3u/%-10u | cost: %3u/%-10u\n", f->rooms[i].name,
				f->rooms[i].pre[CUR], f->rooms[i].pre[OLD],
				f->rooms[i].cost[CUR], f->rooms[i].cost[OLD]);
}

void			print_cost(t_farm *f)
{
	unsigned	i;

	i = -1;
	while (++i < f->end->lnk.lst->len)
		ft_printf("{fred}%s cost %d{}\n", (f->rooms + f->end->lnk.arr[i])->name,
			(f->rooms + f->end->lnk.arr[i])->cost[CUR]);
}
