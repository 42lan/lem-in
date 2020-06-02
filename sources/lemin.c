/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 15:30:46 by abaisago          #+#    #+#             */
/*   Updated: 2020/06/02 19:50:12 by abaisago         ###   ########.fr       */
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
	if (parse_input(hmap) == SUCCESS)
		if (resolve() == SUCCESS)
			send_ants();
	final_free(hmap);
	return (SUCCESS);
}
