/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 19:50:23 by abaisago          #+#    #+#             */
/*   Updated: 2020/04/16 13:55:57 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H
# include "libft.h"
# include "lemin.h"
# include <stddef.h>

int		dbg_print_room(void *content, size_t size, unsigned pos, unsigned max);
void	dbg_hmap_print(t_list *hmap);
void	dbg_farm_print(t_farm *farm);
void	print_paths_from(t_room *start);

/*
** DEBUG_H
*/
#endif
