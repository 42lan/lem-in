/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:25:39 by abosch            #+#    #+#             */
/*   Updated: 2020/06/03 07:11:54 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "lemin.h"

# define FIRST	0
# define FULL	1
# define SIMPLE	2

int				dfs(t_farm *f, t_room *start, t_room *target, t_byte type);
void			orient_path_to(t_farm *f, t_room *target, t_byte rev);
int				resolve(t_farm *f);
unsigned		get_cost(t_farm *f);
unsigned		cost_by_path(t_room *target);
void			recount_cost(t_farm *f);
unsigned		get_nb_paths(t_farm *f);
unsigned		get_max_cost(unsigned *ants_by_path, unsigned *paths_len,
					unsigned nb_paths);
t_byte			is_mixed_path(t_farm *f);
void			remove_deadend(t_farm *f);

#endif
