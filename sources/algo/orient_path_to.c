/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orient_path_to.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 20:15:42 by amalsago          #+#    #+#             */
/*   Updated: 2020/04/15 20:34:26 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "lemin.h"

static void		print_paths_from(t_room *start)
{
	t_room		*room;
	unsigned	begin;
	unsigned	i;

	begin = -1;
	while (++begin < start->LINK_LEN)
		if (start->link.dir[begin] == INWARD)
		{
			i = -1;
			room = ROOMS + start->link.arr[begin];
			ft_printf("%s -> %s ", start->name, room->name);
			while (++i < room->LINK_LEN)
				if (LINK_DIR[i] == INWARD)
				{
					room = ROOMS + LINK_ARR[i];
					ft_printf("-> %s ", room->name);
					i = -1;
				}
			ft_putchar('\n');
		}
}

void	orient_path_to(t_room *target)
{
	t_room		*room;
	t_room		*prev;
	unsigned	i;

	room = target;
	while (room->cost[CUR] != 0)
	{
		prev = ROOMS + room->pre[CUR];
		i = -1;
		while (prev->link.arr[++i] != room->index)
			;
		prev->link.dir[i] = INWARD;
		room = prev;
	}
	print_paths_from(room);
}
