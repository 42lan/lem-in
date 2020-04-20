/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:35:09 by abosch            #+#    #+#             */
/*   Updated: 2020/04/19 23:12:34 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEL_H
# define DEL_H

#include <stddef.h>

void	del_link_list(void *content, size_t size);
void	del_link(void *content, size_t size);
void	del_room(void *content);
void	final_free(void);

#endif
