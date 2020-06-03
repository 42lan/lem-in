/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 15:30:46 by abaisago          #+#    #+#             */
/*   Updated: 2020/06/03 07:13:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "parsing.h"
#include "del.h"
#include "algo.h"
#include "debug.h"
#include "tools.h"

#include <stdlib.h>

int			lemin(int ac, char **av)
{
	t_list	hmap[HMAP_SIZE];

	hmap_init(hmap);
	if (parse_input(farm(), hmap) == SUCCESS)
		if (resolve(farm()) == SUCCESS)
			send_ants(farm());
	final_free(farm(), hmap);
	return (SUCCESS);
}
