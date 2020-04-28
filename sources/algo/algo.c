/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 22:01:45 by abaisago          #+#    #+#             */
/*   Updated: 2020/04/28 17:31:49 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "debug.h"
#include "lemin.h"
#include "tools.h"

void	resolve()
{
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
