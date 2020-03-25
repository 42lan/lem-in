/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 10:53:53 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/25 19:19:44 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

#include "lemin.h"

void		hmap_init(t_list *hmap)
{
	int		i;

	i = -1;
	while (++i < HMAP_SIZE)
	{
		hmap[i].head = NULL;
		hmap[i].size = 0;
	}
}
