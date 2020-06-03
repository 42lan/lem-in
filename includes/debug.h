/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 19:50:23 by abaisago          #+#    #+#             */
/*   Updated: 2020/06/03 07:04:26 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H
# include "libft.h"
# include "lemin.h"
# include <stddef.h>

# define DEBUGP	0
# define CL		0
# define CL_O	0
# define DFS	0
# define BACKT	0

int		dbg_print_room(void *content, size_t size, unsigned pos, unsigned max);
void	dbg_hmap_print(t_list *hmap);
void	dbg_farm_print(t_farm *farm);
void	print_paths_from(t_farm *f, t_room *start);
void	show_orien(t_room *room);
void	show_orien_name(const char *name);
void	print_map_cost();
void	print_state(t_farm *f);
void	print_ant_by_path(t_farm *f);
void	print_from_start2end(t_farm *f);
void	print_cost(t_farm *f);

/*
** DEBUG_H
*/
#endif
