/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 19:30:43 by abaisago          #+#    #+#             */
/*   Updated: 2020/06/02 19:49:31 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	reset_info(void)
{
	unsigned	i;

	i = -1;
	while (++i < g_farm.size)
	{
		ROOMS[i].pre[OLD] = -1;
		ROOMS[i].pre[CUR] = -1;
		ROOMS[i].cost[OLD] = -1;
		ROOMS[i].cost[CUR] = -1;
	}
}

void	reset_all(void)
{
	unsigned	i;
	unsigned	j;
	t_room		*room;

	i = -1;
	while (++i < g_farm.size)
	{
		room = ROOMS + i;
		room->pre[OLD] = -1;
		room->pre[CUR] = -1;
		room->cost[OLD] = -1;
		room->cost[CUR] = -1;
		j = -1;
		while (++j < LINK_SIZE)
			LINK_DIR[j] = DUPLEX;
	}
}
