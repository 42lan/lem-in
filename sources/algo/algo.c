/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 22:01:45 by abaisago          #+#    #+#             */
/*   Updated: 2020/04/29 16:49:36 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "debug.h"
#include "lemin.h"
#include "tools.h"

void	resolve()
{
	if (dfs(g_farm.start, g_farm.end, FULL) == FAILURE)
		ft_printerr("Invalid map: No path between Start and End\n");
	orient_path_to(g_farm.end);
	/* print_paths_from(g_farm.start); */
	reset_info();
	while (dfs(g_farm.start, g_farm.end, FULL) == SUCCESS)
	{
		orient_path_to(g_farm.end);
		/* print_paths_from(g_farm.start); */
		reset_info();
	}
	ft_printf("\n==============================================\n");
	print_paths_from(g_farm.start);
	ft_printf("\n\n");
	send_ants();
}
