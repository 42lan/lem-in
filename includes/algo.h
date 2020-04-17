/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:25:39 by abosch            #+#    #+#             */
/*   Updated: 2020/04/16 22:03:27 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "lemin.h"

# define FIRST 0
# define FULL 1

void		remove_deadend(void);
int			dfs(t_room *start, t_room *target, t_byte type);
void		orient_path_to(t_room *target);
void		resolve();

#endif
