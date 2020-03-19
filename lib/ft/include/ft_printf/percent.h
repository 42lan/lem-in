/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:59:31 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/22 15:05:09 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERCENT_H
# define PERCENT_H
# include "libft.h"
# include "output.h"
# define F_MINUS	1
# define F_PLUS		2
# define F_ZERO		4
# define F_BLANK	8
# define F_HASH		16
# define F_QUOTE	32
# define F_PRECI	64
# define F_NEG		128

# define SIZE_H		1
# define SIZE_HH	2
# define SIZE_L		3
# define SIZE_LL	4
# define SIZE_LLL	5
# define SIZE_J		6
# define SIZE_Z		7

typedef struct		s_spec
{
	char			flags;
	char			size;
	int				diff;
	int				width;
	char			*prefix;
	int				prefix_len;
	int				precision;
}					t_spec;

typedef void		(*t_typefunc)(va_list ap, t_spec *, t_buf *);

typedef struct		s_typetab
{
	char			type;
	t_typefunc		func;
}					t_typetab;

void				type_b(va_list ap, t_spec *spec, t_buf *buf);
void				type_bb(va_list ap, t_spec *spec, t_buf *buf);
void				type_c(va_list ap, t_spec *spec, t_buf *buf);
void				type_cc(va_list ap, t_spec *spec, t_buf *buf);
void				type_dd(va_list ap, t_spec *spec, t_buf *buf);
void				type_di(va_list ap, t_spec *spec, t_buf *buf);
void				type_f(va_list ap, t_spec *spec, t_buf *buf);
void				type_ff(va_list ap, t_spec *spec, t_buf *buf);
void				type_k(va_list ap, t_spec *spec, t_buf *buf);
void				type_s(va_list ap, t_spec *spec, t_buf *buf);
void				type_ss(va_list ap, t_spec *spec, t_buf *buf);
void				type_r(va_list ap, t_spec *spec, t_buf *buf);
void				type_o(va_list ap, t_spec *spec, t_buf *buf);
void				type_oo(va_list ap, t_spec *spec, t_buf *buf);
void				type_p(va_list ap, t_spec *spec, t_buf *buf);
void				type_u(va_list ap, t_spec *spec, t_buf *buf);
void				type_uu(va_list ap, t_spec *spec, t_buf *buf);
void				type_x(va_list ap, t_spec *spec, t_buf *buf);
void				type_xx(va_list ap, t_spec *spec, t_buf *buf);
void				type_default(char letter, t_spec *spec, t_buf *buf);

void				percent(va_list og, va_list ap, char **str, t_buf *buf);
void				write_percent(t_spec *spec, t_str *conv, t_buf *buf);

/*
** PERCENT_H
*/
#endif
