/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uncomment_raw_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 11:27:17 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/17 11:34:36 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** This function receives a raw input containing comments and incorrect inst-
** ructions and returns a list with only correct data number_of_ants, commands,
** the_rooms and the_links
*/

t_list				*uncomment_raw_input(t_list *raw_input)
{
	size_t			size;
	t_list_link		*tmp;
	t_list_link		*line;
	t_list			*uncommented_input;

	size = raw_input->size;
	tmp = raw_input->head;
	if (!(uncommented_input = ft_list_init()))
	{
		if (EMF)
			ft_dprintf(2, "ft_list_init() failed in uncomment_raw_input()\n");
		return (NULL);
	}
	while (size--)
	{
		if (is_invalid_line((char *)(tmp->content)) == FAILURE)
		{
			line = ft_list_link_new(tmp->content, tmp->content_size);
			ft_list_push(uncommented_input, line);
		}
		tmp = tmp->next;
	}
	return (uncommented_input);
}
