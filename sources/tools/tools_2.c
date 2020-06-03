/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 13:12:51 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/03 06:29:18 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "debug.h"

void			print_state(t_farm *f)
{
	unsigned	i;

	i = 1;
	while (++i < f->end->lnk.lst->len)
		if (f->end->lnk.dir[i] == ALLOWED)
			ft_printf("room %s, costs %d\n",
				(f->rooms + f->end->lnk.arr[i])->name,
				(f->rooms + f->end->lnk.arr[i])->cost[CUR]);
}

void			print_ant_by_path(t_farm *f)
{
	unsigned	i;
	unsigned	total;

	i = -1;
	total = 0;
	ft_printf("\n-----------------------\n");
	while (++i < f->nb_paths)
	{
		ft_printf("%d %d\n", i, f->ants_by_path[i]);
		total += f->ants_by_path[i];
	}
	ft_printf("TOTAL %d\n", total);
	ft_printf("-----------------------\n");
}

void			print_from_start2end(t_farm *f)
{
	unsigned	i;
	unsigned	j;
	t_room		*room;

	i = -1;
	j = -1;
	while (++i < f->start->lnk.lst->len)
		if (f->start->lnk.dir[i] == BLOCKED)
		{
			ft_printf("{fred}%s{} ", f->start->name);
			room = f->rooms + f->start->lnk.arr[i];
			j = -1;
			while (++j < room->lnk.lst->len)
				if (room->lnk.dir[j] == BLOCKED)
				{
					if (f->rooms + room->lnk.arr[j] == f->end)
						ft_printf("{fred}%s{}\n", room->name);
					else
						ft_printf("%s ", room->name);
					room = f->rooms + room->lnk.arr[j];
					j = -1;
				}
		}
}
