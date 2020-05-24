/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 17:17:58 by abaisago          #+#    #+#             */
/*   Updated: 2020/05/24 23:28:40 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "del.h"
#include "debug.h"
#include "tools.h"
#include "lib.h"

#include <errno.h>
#include <string.h>

//TODO Redo with strtoll
static int		read_room(t_room *room, char *line)
{
	room->name = ft_strsub(line, 0, ft_strclen(line, ' '));
	while (ft_isprint(*line) && *line != ' ' && *line != '-')
		++line;
	if (!ft_isspace(*line) || !ft_isdigit(*(line + 1)))
		return (FAILURE);
	++line;
	room->coord.x = ft_atoll(line);
	if (overflowed(line, room->coord.x) == SUCCESS)
		return (FAILURE);
	line += ft_strspn(line, "0123456789");
	if (!ft_isspace(*line) || !ft_isdigit(*(line + 1)))
		return (FAILURE);
	++line;
	room->coord.y = ft_atoll(line);
	if (overflowed(line, room->coord.x) == SUCCESS)
		return (FAILURE);
	line += ft_strspn(line, "0123456789");
	if (*line != '\0')
		return (FAILURE);
	return (SUCCESS);
}

static int		handle_comments(t_room *room, char *line)
{
	if (ft_strequ(line, "##start"))
		room->flags = F_START;
	else if (ft_strequ(line, "##end"))
		room->flags = F_END;
	else if (line[0] != '#')
		return (FAILURE);
	return (SUCCESS);
}

static int		handle_room(t_list *hmap, t_list *room_list, t_room *room,
					unsigned index)
{
	room->link.list = ft_list_init();
	room->index = index;
	ft_memset(room->pre, -1, sizeof(room->pre));
	ft_memset(room->cost, -1, sizeof(room->cost));
	if (hmap_add(hmap, room) == FAILURE)
	{
		ft_list_del(&(room->link.list), &del_link_list);
		return (FAILURE);
	}
	ft_list_push(room_list, ft_list_link_new(room, sizeof(*room)));
	return (SUCCESS);
}

static int		get_rooms(t_list *hmap, t_list *room_list, char **line)
{
	t_room		room;
	unsigned	index;

	index = 0;
	ft_bzero(&room, sizeof(room));
	while (readline(line, 0))
	{
		if (*line[0] == 'L')
			return (FAILURE);
		if (handle_comments(&room, *line) == SUCCESS)
		{
			ft_strdel(line);
			continue ;
		}
		if (read_room(&room, *line) == FAILURE)
		{
			ft_strdel(&room.name);
			return (FAILURE);
		}
		if (handle_room(hmap, room_list, &room, index++) == FAILURE)
			return (FAILURE);
		ft_bzero(&room, sizeof(room));
		ft_strdel(line);
	}
	return (SUCCESS);
}

t_list			*get_room_list(t_list *hmap)
{
	t_list		*room_list;		//TODO: Needs to be freed
	char		*line;

	if ((room_list = ft_list_init()) == NULL)
		ft_printerr("lem-in: get_room_list(t_list malloc): \
			%s\n", strerror(errno));
	if (get_rooms(hmap, room_list, &line) == FAILURE)
		if (!ft_strchr(line, '-'))
			ft_printerr(E_ROOMS);
	if (get_links(hmap, line) == FAILURE)
		ft_printerr(E_LINKS);
	return (room_list);
}
