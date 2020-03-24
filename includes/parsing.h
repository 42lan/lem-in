/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 17:08:51 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/24 18:05:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "lemin.h"

# define HMAP_SIZE 10

typedef struct	s_hmap t_hmap;

struct			s_hmap
{
	t_room		*room;
	t_hmap		*next;
};

void			hmap_init(t_hmap *hmap);
int				hmap_index(char *key);
void			hmap_add(t_hmap *hmap, t_room room);
int				parse_input(t_farm *farm);

/*
**PARSING_H
*/
#endif

