/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 17:16:30 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/28 18:12:59 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "lemin.h"

void	print_help(void);
void	room_index(t_room *room, size_t size, unsigned pos, unsigned max);
int		room_namecmp(t_room *room1, char *room2);

/*
** TOOLS_H
*/
#endif
