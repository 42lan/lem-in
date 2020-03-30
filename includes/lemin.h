/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 09:54:34 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/30 14:06:03 by abaisago         ###   ########.fr       */
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

// Error Management Flag - activable on make EMF="-D EMF=1"
# ifndef EMF
#  define EMF 0
# endif

typedef struct	s_farm t_farm;
typedef struct	s_room t_room;

struct			s_farm
{
	unsigned	ants;
	t_room		*rooms;
	unsigned	size;
};

struct			s_room
{
	char		*name;
	t_ivec2		coord;
	unsigned	index;
	t_byte		flags;
	t_list		*link_list;
	unsigned	*links;
	unsigned	nlinks;
};

/*
************
** LEMIN_H *
************
*/
#endif
