/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improve_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 23:26:35 by amalsago          #+#    #+#             */
/*   Updated: 2020/05/28 13:51:52 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "debug.h"

static unsigned		getlink(t_room *room, t_room *target)
{
	unsigned		i;

	i = 0;
	while (i < LINK_SIZE && target != ROOMS + LINK_ARR[i])
		i++;
	return (i);
}

static void			return2destroy(t_room *room, t_room *target)
{
	unsigned		i;
	unsigned		j;

	i = -1;
	while (room != target)
	{
		/* ft_printf("Current %s", room->name); */
		while (++i < LINK_SIZE)
			if (LINK_DIR[i] == ((target == END) ? BLOCKED : ALLOWED))
			{
				/* ft_printf(", Next %s\n", (ROOMS+LINK_ARR[i])->name); */
				break ;
			}
		if (ROOMS + LINK_ARR[i] == target)
		{
			LINK_DIR[i] = DUPLEX;
			j = room->index;
		}
		room = ROOMS + LINK_ARR[i];
		/* ft_printf("Next? %s", room->name); */
		/* ft_printf("\n"); */
		i = -1;
	}
	/* ft_printf("j =  %d\n", j); */
	/* ft_printf("room = %s\n", room->name); */
	i = 0;
	while (i < LINK_SIZE)
		if ((ROOMS + LINK_ARR[i])->index != j)
			i++;
		else
			break ;
	/* ft_printf("i =  %d\n", i); */
	/* ft_printf("rooms + i =  %s\n", (ROOMS + LINK_ARR[i])->name); */
	/* show_orien(room); */
	/* ft_printf("---\n"); */
	LINK_DIR[i] = DUPLEX;
	/* show_orien(room); */
}

unsigned			getcostfrom(t_room *room, t_room *target)
{
	unsigned		i;
	unsigned		cost;

	i = -1;
	cost = 0;
	while (++i < LINK_SIZE)
		if (LINK_DIR[i] == ((target == START) ? ALLOWED : BLOCKED))
		{
			cost++;
			room = ROOMS + LINK_ARR[i];
			i = -1;
		}
	return (cost + 1);
}


static void			end_side(t_room *room)
{
	unsigned		i;
	unsigned		j;
	unsigned		cost1;
	unsigned		cost2;
	t_room			*r1;
	t_room			*r2;

	i = j = -1;
	cost1 = cost2 = 0;
	r1 = r2 = NULL;
	/* ft_printf(">>>>>>>>>%s<<<<<<<<<<<\n", room->name); */
	while (++i < LINK_SIZE && !r1)
		if (LINK_DIR[i] == BLOCKED)
			r1 = ROOMS + LINK_ARR[i];
	cost1 = getcostfrom(r1, END);
	/* ft_printf(">>>%s cost %d\n", r1->name, cost1); */
	i -= 1;;
	j = i;
	while (++i < LINK_SIZE && !r2)
		if (LINK_DIR[i] == BLOCKED)
			r2 = ROOMS + LINK_ARR[i];
	cost2 = getcostfrom(r2, END);
	/* ft_printf(">>>%s cost %d\n", r2->name, cost2); */
	if (cost1 > cost2)
	{
		return2destroy(r1, END);
		LINK_DIR[j] = DUPLEX;
	}
	else
	{
		return2destroy(r2, END);
		LINK_DIR[i] = DUPLEX;
	}
}

static void			start_side(t_room *room)
{
	unsigned		i;
	t_room			*r1;
	t_room			*r2;

	i = -1;
	r1 = r2 = NULL;
	/* show_orien(room); */
	/* ft_printf(">>>>>>>>>%s<<<<<<<<<<<\n", room->name); */
	while (++i < LINK_SIZE && !r1)
		if (LINK_DIR[i] == ALLOWED)
			r1 = ROOMS + LINK_ARR[i];
	r1->cost[CUR] = getcostfrom(r1, START);
	/* ft_printf("=====r1 = %s %d======\n", r1->name, r1->cost[CUR]); */
	i -= 1;
	while (++i < LINK_SIZE && !r2)
		if (LINK_DIR[i] == ALLOWED)
			r2 = ROOMS + LINK_ARR[i];
	r2->cost[CUR] = getcostfrom(r2, START);
	/* ft_printf("=====r2 = %s %d======\n", r2->name, r2->cost[CUR]); */
	/* ft_printf("r1 = %s cost %d\n", r1->name, r1->cost[CUR]); */
	/* ft_printf("r2 = %s cost %d\n", r2->name, r2->cost[CUR]); */
	/* ft_printf(">>>>>>%s\n", (ROOMS + LINK_DIR[getlink(room, r1)])->name); */
	/* ft_printf(">>>>>>%s\n", (ROOMS + LINK_DIR[getlink(room, r2)])->name); */
	if (r1->cost[CUR] > r2->cost[CUR])
	{
		return2destroy(r1, START);
		LINK_DIR[getlink(room, r1)] = DUPLEX;
	}
	else
	{
		return2destroy(r2, START);
		LINK_DIR[getlink(room, r2)] = DUPLEX;
	}
}

void				improve_paths(void)
{
	unsigned		i;
	unsigned		j;
	unsigned		k;
	t_room			*room;
	t_room			*next;

	i = -1;
	room = next = NULL;
	while (++i < END->LINK_LEN)
		if (END->link.dir[i] == ALLOWED)
		{
			room = ROOMS + END->link.arr[i];
			while (room != START)
			{
				/* ft_printf("actual room = %s\n", room->name); */
				j = -1;
				k = 0;
				while (++j < LINK_SIZE)
					if (LINK_DIR[j] == ALLOWED)
					{
						k++;
						/* ft_printf("link = %s\n", (ROOMS+LINK_ARR[j])->name); */
						next = ROOMS + LINK_ARR[j];
					}
				/* ft_printf("k = %d\n", k); */
				if (k > 1)
				{
					// TODO remove link
					start_side(room);
					end_side(room);
					return ;
				}
				/* ft_printf("next room = %s\n", room->name); */
				room = next;
				/* ft_printf("\n"); */
			}
		}
}
