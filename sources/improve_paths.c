/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improve_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 23:26:35 by amalsago          #+#    #+#             */
/*   Updated: 2020/05/27 23:28:14 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static unsigned		getlink(t_room *room, t_room *target)
{
	unsigned	i;

	i = 0;
	while (i < LINK_SIZE && target != ROOMS + LINK_ARR[i])
		i++;
	return (i);
}

static unsigned			getcostfrom(t_room *room)
{
	unsigned	i;
	unsigned	j;

	i = -1;
	j = 0;
	while (room != END)
		while (++i < room->LINK_LEN)
			if (LINK_DIR[i] == BLOCKED)
			{
				room = ROOMS + LINK_ARR[i];
				j++;
			}
	return (j);
}

static void				return2destroy(t_room *room)
{
	unsigned		i;
	unsigned		j;

	i = 0;
	while (room != END)
	{
		while (i < LINK_SIZE && LINK_DIR[i] != BLOCKED)
			i++;
		if (ROOMS + LINK_ARR[i] == END)
		{
			LINK_DIR[i] = DUPLEX;
			j = room->index;
		}
		room = ROOMS + LINK_ARR[i];
	}
	i = 0;
	while (i < LINK_SIZE && LINK_ARR[i] != j)
		i++;
	LINK_DIR[i] = DUPLEX;
}

static void				end_side(t_room *room)
{
	unsigned	i = -1;
	unsigned	j = -1;
	unsigned	cost1 = 0 ;
	unsigned	cost2 = 0 ;

	while (++i < LINK_SIZE && LINK_DIR[i] != BLOCKED)
		cost1 = getcostfrom(ROOMS + LINK_ARR[i]);
	j = i;
	while (++i < LINK_SIZE && LINK_DIR[i] != BLOCKED)
		cost2 = getcostfrom(ROOMS + LINK_ARR[i]);
	if (cost1 > cost2)
		LINK_DIR[j] = DUPLEX;
	else
		LINK_DIR[i] = DUPLEX;
}

static void				start_side(t_room *room)
{
	t_room		*r1 = NULL;
	t_room		*r2 = NULL;
	unsigned	i = -1;

	while (++i < LINK_SIZE && !r1)
		if (LINK_DIR[i] == ALLOWED)
			r1 = ROOMS + LINK_ARR[i];
	while (++i < LINK_SIZE && !r2)
		if (LINK_DIR[i] == ALLOWED)
			r2 = ROOMS + LINK_ARR[i];
	if (r1->cost[CUR] > r2->cost[CUR])
		LINK_DIR[getlink(room, r1)] = DUPLEX;
	else
		LINK_DIR[getlink(room, r2)] = DUPLEX;
}

void				improve_paths(void)
{
	unsigned	i;
	unsigned	j;
	unsigned	k;
	t_room		*room = NULL;
	t_room		*prev = NULL;
	t_room		*from = NULL;

	i = -1;
	while (++i < END->LINK_LEN)
	{
		if (END->link.dir[i] == ALLOWED)
		{
			from = ROOMS + END->link.arr[i];
			room = ROOMS + END->link.arr[i];
			while (room != START)
			{
				j = -1;
				k = 0;
				while (++j < LINK_SIZE)
				{
					if (LINK_DIR[j] == ALLOWED)	
						k++;
				}
				if (k > 1)
				{
					// TODO remove link
					start_side(room);
					end_side(room);
					break ;
				}
				else
				{
					prev = room;
					room = ROOMS + room->pre[CUR];
				}
			}
		}
	}

}
