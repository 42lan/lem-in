/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 17:17:58 by abaisago          #+#    #+#             */
/*   Updated: 2020/04/07 18:34:57 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

#include "debug.h"
#include "predicates.h"
#include "tools.h"

#include <errno.h>
#include <string.h>

//TODO Redo with strtoll
int			read_room(t_room *room, char *line)
{
	room->name = ft_strsub(line, 0, ft_strclen(line, ' '));
	while (ft_isprint(*line) &&  *line != ' ' && *line != '-')
		++line;
	if (*line != ' ')
		return (FAILURE);
	++line;
	if (!ft_isdigit(*line))
		return (FAILURE);
	room->coord.x = ft_atoll(line);
	if (overflowed(line, room->coord.x))
		return (FAILURE);
	line += ft_strskip(line, ft_isdigit);
	line += ft_strskip_set(line, " \t");
	if (!ft_isdigit(*line))
		return (FAILURE);
	room->coord.y = ft_atoll(line);
	if (overflowed(line, room->coord.x))
		return (FAILURE);
	line += ft_strskip(line, ft_isdigit);
	if (*line != '\0')
		return (FAILURE);
	return (SUCCESS);
}

int			handle_comments(t_room *room, char *line)
{
	if (ft_strequ(line, "##start"))
		room->flags |= F_START;
	else if (ft_strequ(line, "##end"))
		room->flags |= F_END;
	else if (line[0] != '#')
		return (FAILURE);
	return (SUCCESS);
}

void		handle_room(t_list *hmap, t_list *room_list, t_room *room, unsigned index)
{
	room->link.list = ft_list_init();	//TODO: Needs to be freed
	room->index = index;
	ft_memset(room->pre, -1, sizeof room->pre);
	ft_memset(room->cost, -1, sizeof room->cost);
	ft_list_push(room_list, ft_list_link_new(room, sizeof *room));
	hmap_add(hmap, room_list->head->prev->content);
}

t_list		*get_room_list(t_farm *farm, t_list *hmap)
{
	t_list		*room_list;		//TODO: Needs to be freed
	t_room		room;
	char		*line;
	int			ret;
	unsigned	index;

	ft_bzero(&room, sizeof(room));
	room_list = ft_list_init();
	index = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (line[0] == 'L')
			break ;
		if (handle_comments(&room, line) == SUCCESS)
			continue ;
		if (read_room(&room, line) == FAILURE)
			break ;
		handle_room(hmap, room_list, &room, index++);
		ft_bzero(&room, sizeof(room));
		ft_strdel(&line);
	}
	if (ret < 0)
		ft_printerr("lem-in: get_rooms(read): %s\n", strerror(errno));
	if (get_links(hmap, line) == FAILURE)
	{
		ft_strdel(&line);
		ft_printerr("lem-in: Incorrect link\n");
	}
	return (room_list);
}
