/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 10:53:53 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/21 17:25:42 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

#include "lemin.h"

void		hmap_init(t_hmap *hmap)
{
	int		i;

	i = -1;
	while (++i < HMAP_SIZE)
	{
		hmap[i].room = NULL;
		hmap[i].next = NULL;
	}
}
