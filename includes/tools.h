/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 17:16:30 by abaisago          #+#    #+#             */
/*   Updated: 2020/06/03 07:05:45 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "lemin.h"

void		sort_paths(void);
t_byte		contains_whitespace(char *line);
t_byte		overflowed(char *str, long long num);
t_byte		start_links_end(t_farm *f);
int			room_namecmp(t_room *room1, char *room2);
int			room_indexcmp(unsigned room1, unsigned room2);
void		room_index(t_room *room, size_t size, unsigned pos, unsigned max);
void		reset_info(t_farm *f);
void		reset_all(t_farm *f);

/*
** TOOLS_H
*/
#endif
