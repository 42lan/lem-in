/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:35:09 by abosch            #+#    #+#             */
/*   Updated: 2020/04/17 20:38:17 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEL_H
# define DEL_H

#include <stddef.h>

void	del_link_list(void *no, size_t u);
void	final_free(void);

#endif
