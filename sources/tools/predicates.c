/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 22:14:44 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/03 06:45:58 by amalsago         ###   ########.fr       */
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
