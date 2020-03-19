/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 21:27:20 by abaisago          #+#    #+#             */
/*   Updated: 2019/04/01 15:03:31 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "output.h"
#include "type_utils.h"

#include <stdlib.h>

void	type_cc(va_list ap, t_spec *spec, t_buf *buf)
{
	t_str		conv;
	wchar_t		c;

	c = va_arg(ap, wchar_t);
	conv.str = ft_wchar_utfe(c);
	conv.len = ft_strlen(conv.str);
	if (conv.len == 0)
		conv.len = 1;
	spec->flags &= ~(F_HASH | F_PLUS | F_BLANK | F_PRECI);
	spec->precision = 0;
	write_percent(spec, &conv, buf);
	free(conv.str);
}

void	type_ss(va_list ap, t_spec *spec, t_buf *buf)
{
	t_str		conv;
	wchar_t		*wide;
	char		null[7];

	wide = va_arg(ap, wchar_t*);
	if (wide == NULL)
		conv.str = ft_strcpy(null, "(null)");
	else
		conv.str = ft_wstr_utfe(wide);
	conv.len = ft_strlen(conv.str);
	spec->flags &= ~(F_PLUS | F_HASH | F_BLANK);
	if (spec->precision < conv.len && spec->flags & F_PRECI)
	{
		conv.len = ft_utfecut_index(conv.str, spec->precision);
		spec->precision = conv.len;
	}
	else
		spec->precision = conv.len;
	write_percent(spec, &conv, buf);
	if (wide != 0)
		free(conv.str);
}
