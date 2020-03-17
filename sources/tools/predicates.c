/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 22:14:44 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/17 10:34:25 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			is_number(const char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (FAILURE);
	return (SUCCESS);
}

int			is_command(const char *str)
{
	if (ft_strequ(str, "##start") || ft_strequ(str, "##end"))
		return (SUCCESS);
	return (FAILURE);
}

int			is_invalid_line(const char *str)
{
	if (str[0] == '#' && is_command(str) == FAILURE)
		return (SUCCESS);
	return (FAILURE);
}
