/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 22:01:45 by abaisago          #+#    #+#             */
/*   Updated: 2020/05/06 18:15:30 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "debug.h"
#include "lemin.h"
#include "tools.h"
#include "colors.h"

#include <limits.h>

void	resolve()
{
	unsigned	curr_cost;
	unsigned	last_cost;

	curr_cost = 0;
	last_cost = UINT_MAX;
	/* if (dfs(g_farm.start, g_farm.end, FULL) == FAILURE) */
	/* 	ft_printerr("Invalid map: No path between Start and End\n"); */
	/* orient_path_to(g_farm.end); */
	/* print_paths_from(g_farm.start); */
	/* reset_info(); */
	while (dfs(g_farm.start, g_farm.end, FULL) == SUCCESS)
	{
		orient_path_to(END, REV_NO);
		/* print_paths_from(g_farm.start); */
		curr_cost = get_cost();
		/* ft_printf(SGR_FG_GREEN"CURR COST : %u\n"SGR_NORMAL, curr_cost); */
		if (curr_cost < last_cost)
			last_cost = curr_cost;
		else
		{
			/* ft_printf(SGR_FG_RED"LAST ORIENT_PATH_TO WILL BE REVERTED\n"SGR_NORMAL); */
			orient_path_to(END, REV_YES);
			break ;
		}
		reset_info();
	}
	print_paths_from(g_farm.start);
	/* ft_printf("\n==============================================\n"); */
	/* print_paths_from(g_farm.start); */
	/* ft_printf("\n\n"); */
	/* send_ants(); */
}
