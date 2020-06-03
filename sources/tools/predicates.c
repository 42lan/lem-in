/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 22:14:44 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/03 07:58:20 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "lib.h"

t_byte			start_links_end(t_farm *f)
{
	unsigned	i;

	i = -1;
	while (++i < f->start->lnk.lst->len)
		if (f->rooms + f->start->lnk.arr[i] == f->end)
			return (SUCCESS);
	return (FAILURE);
}

t_byte			contains_whitespace(char *line)
{
	unsigned	i;

	i = -1;
	while (++i < ft_strlen(line))
		if (ft_iswhitespace(line[i]))
			return (SUCCESS);
	return (FAILURE);
}

t_byte			overflowed(char *str, long long num)
{
	size_t		zeros;
	size_t		digits;

	zeros = ft_strskip_set(str, "0");
	digits = zeros + ft_strskip(str + zeros, ft_isdigit);
	if (digits - zeros > 10)
		return (SUCCESS);
	else if (!ft_isdigit(str[0]) || num > 4294967295)
		return (SUCCESS);
	return (FAILURE);
}

static t_byte	is_mixed_path_helper(t_farm *f, t_room *room)
{
	unsigned	j;
	unsigned	k;
	t_room		*next;

	while (room != f->start)
	{
		j = -1;
		k = 0;
		while (++j < room->lnk.lst->len)
			if (room->lnk.dir[j] == ALLOWED)
			{
				k++;
				next = f->rooms + room->lnk.arr[j];
			}
		if (k > 1)
			return (SUCCESS);
		room = next;
	}
	return (FAILURE);
}

t_byte			is_mixed_path(t_farm *f)
{
	unsigned	i;
	t_room		*room;

	i = -1;
	while (++i < f->end->lnk.lst->len)
		if (f->end->lnk.dir[i] == ALLOWED)
		{
			room = f->rooms + f->end->lnk.arr[i];
			if (is_mixed_path_helper(f, room) == SUCCESS)
				return (SUCCESS);
		}
	return (FAILURE);
}
