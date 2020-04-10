/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 09:54:34 by amalsago          #+#    #+#             */
/*   Updated: 2020/04/10 15:49:42 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft.h"

# define SUCCESS	0
# define FAILURE	1
# define ERROR		"ERROR\n"
# define F_START	0x01
# define F_END		0x02
# define F_DEAD		0x03
# define CUR		0
# define OLD		1

typedef struct	s_farm t_farm;
typedef struct	s_link t_link;
typedef struct	s_room t_room;

struct			s_farm
{
	t_room		*rooms;
	unsigned	size;
	unsigned	ants_total;
	t_room		*start;
	unsigned	ants_start;
	t_room		*end;
	unsigned	ants_end;
};

struct			s_link
{
	t_list		*list;
	unsigned	*arr;
	t_byte		*dir;
};

struct			s_room
{
	unsigned	index;
	char		*name;
	t_ivec2		coord;
	t_link		link;
	t_byte		flags;
	unsigned	cost[2];
	unsigned	pre[2];
	unsigned	ant_id;
};

extern t_farm g_farm;

int		lemin(int ac, char **av);

/*
************
** LEMIN_H *
************
*/
#endif
