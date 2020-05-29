/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 01:16:37 by amalsago          #+#    #+#             */
/*   Updated: 2020/05/30 01:48:23 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "lib.h"

#include <limits.h>

static void		spot_no_path(void)
{
	unsigned	i;

	i = -1;
	while (++i < END->LINK_LEN)
		if (END->link.dir[i] != ALLOWED)
			(ROOMS + END->link.arr[i])->cost[CUR] = UINT_MAX;
}

static void		ft_swap_byte(t_byte *a, t_byte *b)
{
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}

void			sort_paths(void)
{
	unsigned	i;
	unsigned	j;

	i = -1;
	spot_no_path();
	while (++i < END->LINK_LEN - 1)
	{
		j = -1;
		while (++j < END->LINK_LEN - i - 1)
			if ((ROOMS + END->link.arr[j])->cost[CUR]
				> (ROOMS + END->link.arr[j + 1])->cost[CUR])
			{
				ft_swap_xor(&END->link.arr[j], &END->link.arr[j + 1]);
				ft_swap_byte(&END->link.dir[j], &END->link.dir[j + 1]);
			}
	}
}
