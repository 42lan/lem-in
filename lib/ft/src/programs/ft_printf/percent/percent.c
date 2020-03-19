/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:58:11 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/22 14:53:08 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "percent.h"

#include "args.h"
#include "specifier.h"
#include "type_utils.h"

static t_typetab	g_typetab[] =
{
	{'c', &type_c},
	{'C', &type_cc},
	{'s', &type_s},
	{'S', &type_ss},
	{'r', &type_r},
	{'p', &type_p},
	{'d', &type_di},
	{'i', &type_di},
	{'D', &type_dd},
	{'o', &type_o},
	{'O', &type_oo},
	{'u', &type_u},
	{'U', &type_uu},
	{'x', &type_x},
	{'X', &type_xx},
	{'b', &type_b},
	{'B', &type_bb},
	{'f', &type_f},
	{'F', &type_ff},
	{'k', &type_k},
	{0, 0}
};

static t_typefunc	get_type_function(char c)
{
	int		i;

	i = 0;
	while (g_typetab[i].type != c && g_typetab[i].type != 0)
		++i;
	return (g_typetab[i].func);
}

void				percent(va_list og, va_list ap, char **str, t_buf *buf)
{
	t_spec		spec;
	t_typefunc	function;

	++(*str);
	get_arg(og, ap, str);
	get_specifier(&spec, str, ap);
	function = get_type_function(**str);
	if (function != 0)
		function(ap, &spec, buf);
	else
		type_default(**str, &spec, buf);
	if (**str == '\0')
		(*str) -= 1;
}

void				write_percent(t_spec *spec, t_str *conv, t_buf *buf)
{
	get_diff(spec, conv->len);
	if (spec->flags & F_MINUS)
	{
		put_prefix(buf, spec);
		put_preci(buf, spec, conv);
		write_str(buf, conv->str, conv->len);
		put_width(buf, spec, conv->len);
		return ;
	}
	if (spec->flags & F_ZERO)
	{
		put_prefix(buf, spec);
		put_width(buf, spec, conv->len);
	}
	else
	{
		put_width(buf, spec, conv->len);
		put_prefix(buf, spec);
	}
	put_preci(buf, spec, conv);
	write_str(buf, conv->str, conv->len);
}
