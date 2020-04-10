/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 17:08:51 by abaisago          #+#    #+#             */
/*   Updated: 2020/04/10 14:04:00 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "lemin.h"

# define HMAP_SIZE 4096

void			hmap_init(t_list *hmap);
int				hmap_index(const char *key);
int				hmap_add(t_list *hmap, t_room *room);

unsigned		get_ants();
t_list			*get_room_list(t_farm *farm, t_list *hmap);
int				get_links(t_list *hmap, char *line);

int				parse_input(t_farm *farm, t_list *hmap);

/*
**PARSING_H
*/
#endif

