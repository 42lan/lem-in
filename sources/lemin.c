/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 15:30:46 by abaisago          #+#    #+#             */
/*   Updated: 2020/05/23 02:52:41 by amalsago         ###   ########.fr       */
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

t_byte		start_links_end(void)
{
	unsigned	i;

	i = -1;
	while (++i < START->LINK_LEN)
		if (ROOMS + START->link.arr[i] == END)
			return (SUCCESS);
	return (FAILURE);
}


	hmap_init(hmap);
	if (parse_input(hmap) == FAILURE)
		exit(EXIT_FAILURE);
	remove_deadend();
	/* dbg_farm_print(&g_farm); */
	if (start_links_end() == SUCCESS)
	send_ants();
	final_free();
	return (SUCCESS);
}
