/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 21:53:28 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/28 20:47:04 by abaisago         ###   ########.fr       */
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
