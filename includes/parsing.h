/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 17:08:51 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/25 21:12:27 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "lemin.h"

# define HMAP_SIZE 4096

void			hmap_init(t_list *hmap);
int				hmap_index(const char *key);
void			hmap_add(t_list *hmap, t_room *room);
void			hmap_print(t_list *hmap);
int				parse_input(t_farm *farm, t_list *hmap);
void			get_links(t_list *hmap, char *line);
void			get_links(t_list *hmap, char *line);

/*
**PARSING_H
*/
#endif

