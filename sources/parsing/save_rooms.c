/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:24:54 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/17 14:28:21 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** This function iterate through uncommented_input, save and returns rooms
*/

t_list				*save_rooms(t_list *uncommented_input, int size)
{
	t_list_link		*tmp;
	t_list_link		*room;
	t_list			*rooms;

	tmp = uncommented_input->head;
	if (!(rooms = ft_list_init()))
	{
		if (EMF)
			ft_printerr("ft_list_init() failed in save_rooms()\n");
		return (NULL);
	}
	// Find place where rooms start (after ##start command)
	while (size--)
	{
		if ((is_command(tmp->content) == SUCCESS) || (is_room(tmp->content) == SUCCESS))
			break ;
		tmp = tmp->next;
	}
	// Save all rooms
	while (size--)
	{
		if ((is_command(tmp->content) == FAILURE) && is_room(tmp->content) == FAILURE)
			break ;
		room = ft_list_link_new(tmp->content, tmp->content_size);
		if (!room
		ft_list_push(rooms, room);
		tmp = tmp->next;
	}
	return (rooms);
}
