/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 09:54:34 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/26 19:10:28 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include "colors.h"
# include "system_libraries.h"

# define SUCCESS 0
# define FAILURE 1
# define ERROR "ERROR\n"
# define F_START 0x00000001
# define F_END 0x00000002

// Error Management Flag - activable on make EMF="-D EMF=1"
# ifndef EMF
#  define EMF 0
# endif

typedef struct	s_farm t_farm;
typedef struct	s_room t_room;

struct			s_farm
{
	unsigned	ants;
	t_list		*rooms;
};

struct			s_room
{
	char		*name;
	t_ivec2		coord;
	unsigned	index;
	t_byte		flags;
	t_list		*links;
};

/*
** LEMIN_H
*/
#endif
