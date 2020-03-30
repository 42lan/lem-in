/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 17:17:58 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/30 14:51:12 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

#include "predicates.h"

#include <errno.h>
#include <string.h>

//TODO Redo with strtoll
int			read_room(t_room *room, char *line)
{
	room->name = ft_strsub(line, 0, ft_strclen(line, ' '));
	while (ft_isprint(*line) &&  *line != ' ' && *line != '-')
		++line;
	if (*line != ' ')
		return (0);
	++line;
	if (!ft_isdigit(*line))
		return (0);
	room->coord.x = ft_atoll(line);
	if (overflowed(line, room->coord.x))
		return (0);
	line += ft_strskip(line, ft_isdigit);
	line += ft_strskip_set(line, " \t");
	if (!ft_isdigit(*line))
		return (0);
	room->coord.y = ft_atoll(line);
	if (overflowed(line, room->coord.x))
		return (0);
	line += ft_strskip(line, ft_isdigit);
	if (*line != '\0')
		return (0);
	return (1);
}

int			handle_comments(t_room *room, char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		room->flags |= F_START;
	else if (ft_strcmp(line, "##end") == 0)
		room->flags |= F_END;
	else if (line[0] != '#')
		return (0);
	return (1);
}

t_list		*get_room_list(t_list *hmap)
{
	t_list		*room_list;		//TODO: Needs to be freed
	t_room		room;
	char		*line;
	int			ret;

	ft_bzero(&room, sizeof(room));
	room_list = ft_list_init();
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (line[0] == 'L')
			break ;
		if (handle_comments(&room, line))
			continue ;
		if (read_room(&room, line) == 0)
			break ;
		room.link_list = ft_list_init();	//TODO: Needs to be freed
		ft_list_push_front(room_list, ft_list_link_new(&room, sizeof room));
		hmap_add(hmap, room_list->head->content);
		ft_bzero(&room, sizeof(room));
		ft_strdel(&line);
	}
	if (ret < 0)
		ft_printerr("lem-in: get_rooms(read): %s\n", strerror(errno));
	get_links(hmap, line);
	return (room_list);
}
