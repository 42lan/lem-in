/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 01:16:37 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/03 13:18:32 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "lib.h"

#include <limits.h>

static void		spot_no_path(t_farm *f)
{
	unsigned	i;

	i = -1;
	while (++i < f->end->lnk.lst->len)
		if (f->end->lnk.dir[i] != ALLOWED)
			(f->rooms + f->end->lnk.arr[i])->cost[CUR] = UINT_MAX;
}

static void		ft_swap_byte(t_byte *a, t_byte *b)
{
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}

void			sort_paths(t_farm *f)
{
	unsigned	i;
	unsigned	j;

	i = -1;
	spot_no_path(f);
	while (++i < f->end->lnk.lst->len - 1)
	{
		j = -1;
		while (++j < f->end->lnk.lst->len - i - 1)
			if ((f->rooms + f->end->lnk.arr[j])->cost[CUR]
				> (f->rooms + f->end->lnk.arr[j + 1])->cost[CUR])
			{
				ft_swap_xor(&f->end->lnk.arr[j], &f->end->lnk.arr[j + 1]);
				ft_swap_byte(&f->end->lnk.dir[j], &f->end->lnk.dir[j + 1]);
			}
	}
}
