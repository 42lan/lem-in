/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 15:30:46 by abaisago          #+#    #+#             */
/*   Updated: 2020/04/17 19:58:45 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "parsing.h"
#include "del.h"
#include "algo.h"
#include "debug.h"
#include "tools.h"

#include <stdlib.h>

t_farm	g_farm;

int		lemin(int ac, char **av)
{
	t_list	hmap[HMAP_SIZE];

	hmap_init(hmap);
	if (parse_input(hmap) == FAILURE)
		exit(EXIT_FAILURE);
	remove_deadend();
	dbg_farm_print(&g_farm);
	resolve();
	final_free();
	return (SUCCESS);
}
