/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 19:50:23 by abaisago          #+#    #+#             */
/*   Updated: 2020/05/26 16:55:34 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H
# include "libft.h"
# include "lemin.h"
# include <stddef.h>

# define DEBUGP 0

int		dbg_print_room(void *content, size_t size, unsigned pos, unsigned max);
void	dbg_hmap_print(t_list *hmap);
void	dbg_farm_print(t_farm *farm);
void	print_paths_from(t_room *start);
void	show_orien(t_room *room);
void	print_map_cost();

/*
** DEBUG_H
*/
#endif
