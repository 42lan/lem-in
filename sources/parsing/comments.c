/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 04:01:32 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/03 04:03:35 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "parsing.h"

int		handle_comments(t_room *room, char *line)
{
	if (ft_strequ(line, "##start"))
		room->flags = F_START;
	else if (ft_strequ(line, "##end"))
		room->flags = F_END;
	else if (line[0] != '#')
		return (FAILURE);
	return (SUCCESS);
}
