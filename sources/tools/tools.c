/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 21:53:28 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/28 16:16:08 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_farm(t_farm *farm)
{
	ft_printf("Number of ants: %d\n", farm->ants);
}

void	room_index(t_room *room, size_t size, unsigned pos, unsigned max)
{
	room->index = pos - 1;
}

int		room_namecmp(t_room *room1, char *room2)
{
    return (ft_strcmp(room1->name, room2));
}
