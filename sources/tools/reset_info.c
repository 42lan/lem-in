/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:28:16 by amalsago          #+#    #+#             */
/*   Updated: 2020/04/16 20:39:37 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	reset_info(void)
{
	unsigned	i;

	i = -1;
	while (++i < g_farm.size)
	{
		ROOMS[i].pre[OLD] = ROOMS[i].pre[CUR];
		ROOMS[i].pre[CUR] = -1;
		ROOMS[i].cost[OLD] = ROOMS[i].cost[CUR];
		ROOMS[i].cost[CUR] = -1;
	}
}
