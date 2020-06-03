/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 09:54:34 by amalsago          #+#    #+#             */
/*   Updated: 2020/06/03 04:46:25 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft.h"
# include "errors.h"

# define SUCCESS		0
# define FAILURE		1
# define CUR			0
# define OLD			1
# define REV_NO			0
# define REV_YES		1
# define F_START		0x01
# define F_END			0x02
# define F_DEAD			0x04
# define DUPLEX			0x00
# define ALLOWED		0x01
# define BLOCKED		0x02

# define START			g_farm.start
# define END			g_farm.end
# define ROOMS			g_farm.rooms
# define LINK_ARR		room->link.arr
# define LINK_DIR		room->link.dir
# define LINK_SIZE		room->link.list->len
# define LINK_LEN		link.list->len

typedef struct s_farm	t_farm;
typedef struct s_link	t_link;
typedef struct s_room	t_room;

struct					s_farm
{
	t_room				*rooms;
	unsigned			size;
	unsigned			ants_total;
	t_room				*start;
	unsigned			ants_start;
	t_room				*end;
	unsigned			ants_end;
	unsigned			nb_paths;
	unsigned			*ants_by_path;
};

struct					s_link
{
	t_list				*list;
	unsigned			*arr;
	t_byte				*dir;
};

struct					s_room
{
	unsigned			index;
	char				*name;
	t_ivec2				coord;
	t_link				link;
	t_byte				flags;
	unsigned			cost[2];
	unsigned			pre[2];
	unsigned			ant_id;
};

extern t_farm			g_farm;

int						lemin(int ac, char **av);
t_byte					start_links_end(void);
void					send_ants();

/*
************
** LEMIN_H *
************
*/
#endif
