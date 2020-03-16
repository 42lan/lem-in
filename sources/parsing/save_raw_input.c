/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_raw_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 21:37:29 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/16 21:39:13 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list				*save_raw_input(void)
{
	char			*line;
	t_list_link		*raw_line;
	t_list			*raw_input;

	raw_input = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (!(raw_line = ft_list_link_new(line, ft_strlen(line) + 1)))
		{
			if (EMF)
				ft_dprintf(2, "ft_list_link_new() failed in save_raw_input()");
			return (NULL);
		}
		if (raw_input == NULL)
			raw_input = ft_list_new(raw_line);
		else
			ft_list_push(raw_input, raw_line);
		ft_strdel(&line);
	}
	return (raw_input);
}
