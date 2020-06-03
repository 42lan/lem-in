/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:25:39 by abosch            #+#    #+#             */
/*   Updated: 2020/06/03 04:22:15 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "lemin.h"

# define FIRST	0
# define FULL	1
# define SIMPLE	2

int				dfs(t_room *start, t_room *target, t_byte type);
void			orient_path_to(t_room *target, t_byte rev);
int				resolve(void);
int				resolve(void);
unsigned		get_cost(void);
unsigned		cost_by_path(t_room *target);
void			recount_cost(void);
unsigned		get_nb_paths(void);
unsigned		get_max_cost(unsigned *ants_by_path, unsigned *paths_len,
					unsigned nb_paths);
t_byte			is_mixed_path(void);
void			remove_deadend(void);

#endif
