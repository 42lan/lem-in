/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_raw_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 21:37:29 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/17 11:51:36 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** This function saves received input from STDIN into a t_list
*/

t_list				*save_raw_input(void)
{
	char			*line;
	t_list_link		*raw_line;
	t_list			*raw_input;

	if (!(raw_input = ft_list_init()))
	{
		if (EMF)
			ft_printerr("ft_list_init() failed in save_raw_input()\n");
		return (NULL);
	}
	while (get_next_line(0, &line) > 0)
	{
		if (!(raw_line = ft_list_link_new(line, ft_strlen(line) + 1)))
		{
			if (EMF)
				ft_printerr("ft_list_link_new() failed in save_raw_input()");
			// Need to free raw_input and line?
			//ft_list_del
			//ft_strdel(&line);
			return (NULL);
		}
		ft_list_push(raw_input, raw_line);
		ft_strdel(&line);
	}
	return (raw_input);
}
