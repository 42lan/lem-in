/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 21:53:28 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/26 14:08:08 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_farm(t_farm *farm)
{
	ft_printf("Number of ants: %d\n", farm->ants);
}

int		room_namecmp(t_room *room1, char *room2)
{
    return (ft_strcmp(room1->name, room2));
}
