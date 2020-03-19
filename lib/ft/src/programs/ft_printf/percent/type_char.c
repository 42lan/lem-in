/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:51:28 by abosch            #+#    #+#             */
/*   Updated: 2020/03/09 15:52:11 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "output.h"
#include "percent.h"
#include "type_utils.h"

#include <stdlib.h>

void	type_c(va_list ap, t_spec *spec, t_buf *buf)
{
	t_str		conv;
	char		c;

	if (spec->size == SIZE_L)
	{
		type_cc(ap, spec, buf);
		return ;
	}
	c = (char)va_arg(ap, int);
	conv.str = &c;
	conv.len = 1;
	spec->flags &= ~(F_HASH | F_PLUS | F_BLANK | F_PRECI);
	spec->precision = 0;
	write_percent(spec, &conv, buf);
}

void	type_s(va_list ap, t_spec *spec, t_buf *buf)
{
	t_str		conv;
	char		null[7];

	if (spec->size == SIZE_L)
	{
		type_ss(ap, spec, buf);
		return ;
	}
	conv.str = va_arg(ap, char*);
	if (conv.str == NULL)
		conv.str = ft_strcpy(null, "(null)");
	conv.len = ft_strlen(conv.str);
	spec->flags &= ~(F_PLUS | F_HASH | F_BLANK);
	if (spec->precision < conv.len && spec->flags & F_PRECI)
		conv.len = spec->precision;
	else
		spec->precision = conv.len;
	write_percent(spec, &conv, buf);
}

void	type_r(va_list ap, t_spec *spec, t_buf *buf)
{
	char		*new;
	t_str		conv;
	char		null[7];

	new = va_arg(ap, char*);
	if (new == NULL)
		conv.str = ft_strcpy(null, "(null)");
	else
	{
		if ((conv.str = ft_make_printable(new)) == NULL)
			return ;
	}
	conv.len = ft_strlen(conv.str);
	spec->flags &= ~(F_PLUS | F_HASH | F_BLANK);
	if (spec->precision < conv.len && spec->flags & F_PRECI)
		conv.len = spec->precision;
	else
		spec->precision = conv.len;
	write_percent(spec, &conv, buf);
	if (new != NULL)
		ft_strdel(&conv.str);
}

void	type_p(va_list ap, t_spec *spec, t_buf *buf)
{
	t_str		conv;
	char		str[17];
	char		prefix[3];
	void		*ptr;

	ptr = va_arg(ap, void*);
	conv.str = ft_lluitosa_base((size_t)ptr, 16, str);
	conv.len = ft_strlen(conv.str);
	spec->flags &= ~(F_PLUS | F_BLANK);
	spec->flags |= F_HASH;
	spec->prefix = ft_strcpy(prefix, "0x");
	spec->prefix_len = 2;
	if (spec->flags & F_PRECI)
	{
		if (ptr == 0)
			conv.len = 0;
		spec->flags &= ~F_ZERO;
	}
	write_percent(spec, &conv, buf);
}

void	type_default(char letter, t_spec *spec, t_buf *buf)
{
	t_str		conv;
	char		c[1];

	if (letter == '\0')
		return ;
	c[0] = letter;
	conv.str = c;
	conv.len = 1;
	spec->flags &= ~(F_HASH | F_PLUS | F_BLANK | F_PRECI);
	spec->precision = 0;
	write_percent(spec, &conv, buf);
}
