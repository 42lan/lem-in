/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:13:14 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/22 14:56:22 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "percent.h"

#include "output.h"

void	get_diff(t_spec *spec, int conv_len)
{
	spec->diff = 0;
	if (spec->precision > conv_len)
		spec->diff = spec->precision;
	else
		spec->diff = conv_len;
	if (spec->flags & F_NEG || spec->flags & F_PLUS || spec->flags & F_BLANK)
		spec->diff++;
	if (spec->flags & F_HASH)
		spec->diff += spec->prefix_len;
	if (spec->diff < 0)
		spec->diff = 0;
}

void	put_prefix(t_buf *buf, t_spec *spec)
{
	if (spec->flags & F_NEG)
		write_char(buf, '-', 1);
	else if (spec->flags & F_PLUS)
		write_char(buf, '+', 1);
	else if (spec->flags & F_BLANK)
		write_char(buf, ' ', 1);
	if (spec->flags & F_HASH)
		write_str(buf, spec->prefix, spec->prefix_len);
}

void	put_width(t_buf *buf, t_spec *spec, int conv_len)
{
	if (spec->width < spec->diff || spec->width < conv_len)
		return ;
	if (spec->flags & F_ZERO && !(spec->flags & F_MINUS))
		write_char(buf, '0', spec->width - spec->diff);
	else
		write_char(buf, ' ', spec->width - spec->diff);
}

void	put_preci(t_buf *buf, t_spec *spec, t_str *conv)
{
	if (spec->precision && spec->precision > conv->len)
		write_char(buf, '0', spec->precision - conv->len);
}
