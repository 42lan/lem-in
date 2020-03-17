/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:44:06 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/17 17:44:37 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list				*save_links(t_list *uncommented_input, int size)
{
	t_list_link		*tmp;
	t_list_link		*link;
	t_list			*links;

	tmp = uncommented_input->head;
	if (!(links = ft_list_init()))
	{
		if (EMF)
			ft_printerr("ft_list_init() failed in save_rooms()\n");
		return (NULL);
	}
	// Find place where links start (after rooms)
	while (size--)
	{
		if ((is_link(tmp->content) == SUCCESS) || (is_link(tmp->content) == SUCCESS))
			break ;
		tmp = tmp->next;
	}
	// Save all links
	while (size-- >= 0)
	{
		if (is_link(tmp->content) == FAILURE)
			break ;
		link = ft_list_link_new(tmp->content, tmp->content_size);
		if (!link)
		{
			// links needs to be freed
			if (EMF)
				ft_printerr("ft_list_link_new() failed in save_links()\n");
			return (NULL);
		}
		ft_list_push(links, link);
		tmp = tmp->next;
	}
	return (links);
}
