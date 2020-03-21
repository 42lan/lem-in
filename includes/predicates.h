/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 17:15:38 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/21 17:16:05 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREDICATES_H
# define PREDICATES_H

int		is_invalid_line(const char *str);
int		is_number(const char *str);
int		is_command(const char *str);
int		is_room(char *line);
int		is_link(char *line);

/*
** PREDICATES_H
*/
#endif
