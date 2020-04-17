/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 22:01:45 by abaisago          #+#    #+#             */
/*   Updated: 2020/04/16 22:10:51 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

#include "lemin.h"
#include "tools.h"

void	resolve()
{
	while (dfs(g_farm.start, g_farm.end, FULL) == SUCCESS)
	{
		orient_path_to(g_farm.end);
		reset_info();
	}
}
