/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_room_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 15:38:55 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/19 15:48:55 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				is_valid_room_name(char *name)
{
	if (name[0] == 'L' || name[0] == '#')
		return (FAILURE);
	return (SUCCESS);
}

void			check_room_names(t_list *rooms)
{
	int			size;
	t_list_link	*tmp;

	size = rooms->size;
	tmp = rooms->head;
	while (size-- >= 0)
	{
		if (is_command(tmp->content) == SUCCESS)
		{
			tmp = tmp->next;
			continue ;
		}
		ft_printf("OK: %s\n", tmp->content);
		if (is_valid_room_name(tmp->content) == FAILURE)
		{
			ft_printerr("%s - invalid room name\n", tmp->content);
		}
		tmp = tmp->next;
	}
}
