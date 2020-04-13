/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 15:30:46 by abaisago          #+#    #+#             */
/*   Updated: 2020/04/13 21:42:20 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "parsing.h"

#include "algo.h"

#include <stdlib.h>

t_farm	g_farm;

int		lemin(int ac, char **av)
{
	t_list	hmap[HMAP_SIZE];

	hmap_init(hmap);
	if (parse_input(hmap) == FAILURE)
		exit(EXIT_FAILURE);
	dfs(g_farm.start, g_farm.end, FULL);
	return (SUCCESS);
}
