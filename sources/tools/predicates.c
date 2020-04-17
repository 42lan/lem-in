/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 22:14:44 by amalsago          #+#    #+#             */
/*   Updated: 2020/04/16 20:12:34 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "lib.h"

int				contains_whitespace(char *line)
{
	unsigned	i;

	i = -1;
	while (++i < ft_strlen(line))
		if (ft_iswhitespace(line[i]))
			return (SUCCESS);
	return (FAILURE);
}

int		overflowed(char *str, long long num)
{
	size_t				zeros;
	size_t				digits;

	zeros = ft_strskip_set(str, "0");
	digits = zeros + ft_strskip(str + zeros, ft_isdigit);
	if (digits - zeros > 10)
		return (1);
	else if (!ft_isdigit(str[0]) || num > 4294967295)
		return (1);
	else
		return (0);
}
