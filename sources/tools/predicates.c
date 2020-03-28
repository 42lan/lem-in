/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 22:14:44 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/28 16:14:17 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "lib.h"

int		is_link(char *line)
{
	int				words;

	words = ft_count_words(line, '-');
	if (words == 2)
		return (SUCCESS);
	return (FAILURE);
}

int		is_room(char *line)
{
	int				words;

	words = ft_count_words(line, ' ');
	if (words == 3)
		return (SUCCESS);
	return (FAILURE);
}

int		is_number(const char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (FAILURE);
	return (SUCCESS);
}

int		is_command(const char *str)
{
	if (ft_strequ(str, "##start") || ft_strequ(str, "##end"))
		return (SUCCESS);
	return (FAILURE);
}

int		overflowed(char *str, long long num)
{
	size_t				zeros;
	size_t				digits;

	zeros = ft_strskip_set(str, "0");
	digits = zeros + ft_strskip(str, ft_isdigit);
	if (digits - zeros > 10)
		return (1);
	else if (!ft_isdigit(str[0]) || num > 4294967295)
		return (1);
	else
		return (0);
}
