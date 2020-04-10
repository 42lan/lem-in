/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 15:30:46 by abaisago          #+#    #+#             */
/*   Updated: 2020/04/10 15:44:07 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "parsing.h"

#include <stdlib.h>

int		lemin(int ac, char **av)
{
	t_farm	farm;
	t_list	hmap[HMAP_SIZE];

	hmap_init(hmap);
	if (parse_input(&farm, hmap) == FAILURE)
		exit(EXIT_FAILURE);
	return (SUCCESS);
}
