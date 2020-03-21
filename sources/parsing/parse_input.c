/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 09:32:10 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/21 16:27:02 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include <errno.h>
#include <stddef.h>
#include <string.h>

int			overflowed(char *str, long long num)
{
	size_t				zeros;
	size_t				digits;

	zeros = ft_strskip_set(str, "0");
	digits = zeros + ft_strskip(str, ft_isdigit);
	if (digits - zeros > 10)
		return (1);
	else if (!ft_isdigit(str[0]) || num > 4294967295)
		return (1);
	else
		return (0);
}

unsigned	get_ants()
{
	char		*line;
	long long	ants;

	if (get_next_line(0, &line) < 0)
		ft_printerr("lem-in: get_ants(read): %s\n", strerror(errno));
	ants = ft_atoll(line);
	if (overflowed(line, ants))
		ft_printerr(ERROR);
	line += ft_strskip(line, ft_isdigit);
	line += ft_strskip_set(line, " \t");
	if (*line != '\0')
		ft_printerr(ERROR);
	return (ants);
}

int			read_room(t_room *room, char *line)
{
	room->name = ft_strsub(line, 0, ft_strclen(line, ' '));
	while (ft_isalnum(*line))
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

t_list		*get_rooms()
{
	t_list		*rooms;
	t_room		room;
	char		*line;
	int			ret;

	rooms = ft_list_init();
	while ((ret = get_next_line(0, &line)) > 0)
	{
		ft_bzero(&room, sizeof(room));
		if (ft_strcmp(line, "##start") == 0)
			room.flags &= F_START;
		else if (ft_strcmp(line, "##end") == 0)
			room.flags &= F_END;
		else if (line[0] == '#')
			continue ;
		else if (line[0] == 'L')
			break ;
		if (read_room(&room, line) == 0)
			break;
		//hashmap(rooms, ft_list_link_new(&room, sizeof room));
		ft_strdel(&line);
	}
	if (ret < 0)
		ft_printerr("lem-in: parse_input(read): %s\n", strerror(errno));
	return (rooms);
}

int			parse_input(t_farm *farm)
{
	farm->ants = get_ants();
	farm->rooms = get_rooms(farm);
	return (SUCCESS);
}
