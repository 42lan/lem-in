/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 17:08:51 by abaisago          #+#    #+#             */
/*   Updated: 2020/06/03 04:47:39 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "lemin.h"

# define HMAP_SIZE	4096

void				hmap_init(t_list *hmap);
int					hmap_index(const char *key);
int					hmap_add(t_list *hmap, t_room *room);
int					parse_input(t_list *hmap);
int					readline(char **line, int eof);
unsigned			get_ants(void);
t_list				*get_room_list(t_list *hmap);
int					get_links(t_list *hmap, char *line);
int					handle_comments(t_room *room, char *line);
void				remove_deadend(void);

/*
**PARSING_H
*/
#endif
