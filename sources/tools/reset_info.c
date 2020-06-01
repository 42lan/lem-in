/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:28:16 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/01 20:24:36 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
