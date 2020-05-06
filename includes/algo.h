/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:25:39 by abosch            #+#    #+#             */
/*   Updated: 2020/05/06 17:43:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "lemin.h"

# define FIRST 0
# define FULL 1

void		remove_deadend(void);
int			dfs(t_room *start, t_room *target, t_byte type);
void		orient_path_to(t_room *target, t_byte rev);
void		resolve();
unsigned	get_cost(void);
unsigned	cost_by_path(t_room *target);

#endif
