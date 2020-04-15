/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:28:16 by amalsago          #+#    #+#             */
/*   Updated: 2020/04/15 19:53:15 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	reset_info(void)
{
	unsigned	i;

	i = -1;
	while (++i < g_farm.size)
	{
		ft_memset(ROOMS[i].pre, -1, sizeof ROOMS[i].pre);
		ft_memset(ROOMS[i].cost, -1, sizeof ROOMS[i].cost);
	}
}
