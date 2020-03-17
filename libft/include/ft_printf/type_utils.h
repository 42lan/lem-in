/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:28:14 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/22 15:06:14 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_UTILS_H
# define TYPE_UTILS_H
# include "percent.h"
# include <string.h>

int			get_diff(t_spec *spec, int conv_len);
void		put_width(t_buf *buf, t_spec *spec, int conv_len);
void		put_prefix(t_buf *buf, t_spec *spec);
void		put_preci(t_buf *buf, t_spec *spec, t_str *conv);

size_t		get_cast_arg(va_list ap, char size);
size_t		get_cast_arg_unsigned(va_list ap, char size);

/*
** TYPE_UTILS_H
*/
#endif
