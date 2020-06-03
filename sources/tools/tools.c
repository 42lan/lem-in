/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 21:53:28 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/03 05:14:32 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

void	room_index(t_room *room, size_t size, unsigned pos, unsigned max)
{
	room->index = pos - 1;
}

int		room_namecmp(t_room *room1, char *room2)
{
	return (ft_strcmp(room1->name, room2));
}

int		room_indexcmp(t_room *room1, unsigned *index2)
{
	return (room1->index - *index2);
}
