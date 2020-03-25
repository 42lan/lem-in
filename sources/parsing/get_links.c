/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 20:54:45 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/25 23:16:49 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "lib.h"
#include "debug.h"

#include <errno.h>
#include <stddef.h>
#include <string.h>

int			room_namecmp(t_room *r1, char *r2)
{
    return (ft_strcmp(r1->name, r2));
}

void		inc_links(t_list *hmap, char *line)
{
	int		i1;
	int		i2;
	char	*r1;
	char	*r2;
	t_list	*links;
	t_room	*room;

	if (!(links = ft_list_init()))
		ft_printerr("lem-in: inc_links(malloc): %s\n", strerror(errno));
	if (ft_strchr(line, '-'))
	{
		r1 = ft_strtok(line, "-");
		r2 = ft_strtok(NULL, "-");
		i1 = hmap_index(r1);
		i2 = hmap_index(r2);
		ft_list_print(&hmap[i1], dbg_print_room);
		room = ft_list_find(&hmap[i1], r1, room_namecmp)->content;
		ft_printf("%s\n", room->name);
	}
}

void		get_links(t_list *hmap, char *line)
{
	int		ret;

	if (line[0] == '#')
		ft_strdel(&line);
	else
	{
		inc_links(hmap, line);
		ft_strdel(&line);
	}
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (line[0] == '#')
			continue ;
		inc_links(hmap, line);
		ft_strdel(&line);
	}
}
