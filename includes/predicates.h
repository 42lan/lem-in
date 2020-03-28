/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 17:15:38 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/28 17:39:08 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREDICATES_H
# define PREDICATES_H

int		is_command(const char *str);
int		is_link(char *line);
int		is_number(const char *str);
int		is_room(char *line);
int		overflowed(char *str, long long num);

/*
** PREDICATES_H
*/
#endif
