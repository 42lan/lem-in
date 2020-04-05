/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 09:54:34 by amalsago          #+#    #+#             */
/*   Updated: 2020/04/05 16:32:58 by abosch           ###   ########.fr       */
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
# define BOTH		2
# define ONEWAY		1
# define REVERSE	0

// Error Management Flag - activable on make EMF="-D EMF=1"
# ifndef EMF
#  define EMF 0
# endif

typedef struct	s_farm t_farm;
typedef struct	s_link t_link;
typedef struct	s_room t_room;

struct			s_farm
{
	unsigned	ants;
	t_room		*rooms;
	unsigned	size;
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

/*
************
** LEMIN_H *
************
*/
#endif
