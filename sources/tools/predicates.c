/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 22:14:44 by amalsago          #+#    #+#             */
/*   Updated: 2020/05/24 23:29:39 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "lib.h"

t_byte			start_links_end(void)
{
	unsigned	i;

	i = -1;
	while (++i < START->LINK_LEN)
		if (ROOMS + START->link.arr[i] == END)
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
