/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:48:45 by abosch            #+#    #+#             */
/*   Updated: 2019/04/19 15:17:03 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H
# include "ft_printf.h"
# include <string.h>

typedef struct		s_buf
{
	int				fd;
	int				read;
	int				index;
	char			data[BUFF_SIZE];
}					t_buf;

void				print_buf(t_buf *buf);
void				write_char(t_buf *buf, char c, size_t len);
void				write_str(t_buf *buf, char *str, size_t len);

/*
** SPECIFIER_H
*/
#endif
