/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 17:16:30 by abaisago          #+#    #+#             */
/*   Updated: 2020/05/24 23:21:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "lemin.h"

t_byte		contains_whitespace(char *line);
t_byte		overflowed(char *str, long long num);
t_byte		start_links_end(void);
int			room_namecmp(t_room *room1, char *room2);
int			room_indexcmp(unsigned room1, unsigned room2);
void		room_index(t_room *room, size_t size, unsigned pos, unsigned max);
void		reset_info(void);
void		print_help(void);

/*
** TOOLS_H
*/
#endif
