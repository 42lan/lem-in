/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_floats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:02:25 by abaisago          #+#    #+#             */
/*   Updated: 2019/04/01 20:47:45 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "floats.h"
#include "integers.h"
#include "output.h"
#include "percent.h"

#include <stdlib.h>

void	type_f(va_list ap, t_spec *spec, t_buf *buf)
{
	t_str		conv;
	char		err[5];
	double		nbr;

	if (spec->size == SIZE_LLL)
	{
		type_ff(ap, spec, buf);
		return ;
	}
	nbr = va_arg(ap, double);
	if (!(spec->flags & F_PRECI))
		spec->precision = 6;
	if ((conv.str = ftoa(nbr, spec->precision)) == NULL)
		conv.str = ft_strcpy(err, "(-1)");
	else if (spec->flags & F_QUOTE)
		conv.str = nbr_grouping(&conv, ',', 3);
	conv.len = ft_strlen(conv.str);
	if (!(spec->flags & F_HASH) && spec->precision == 0)
		conv.str[conv.len - 1] = '\0';
	write_percent(spec, &conv, buf);
	free(conv.str);
}

void	type_ff(va_list ap, t_spec *spec, t_buf *buf)
{
	t_str			conv;
	char			err[5];
	long double		nbr;

	if (spec->size == SIZE_L)
	{
		type_f(ap, spec, buf);
		return ;
	}
	nbr = va_arg(ap, long double);
	if (!(spec->flags & F_PRECI))
		spec->precision = 6;
	if ((conv.str = ftoa(nbr, spec->precision)) == NULL)
		conv.str = ft_strcpy(err, "(-1)");
	else if (spec->flags & F_QUOTE)
		conv.str = nbr_grouping(&conv, ',', 3);
	conv.len = ft_strlen(conv.str);
	if (!(spec->flags & F_HASH) && spec->precision == 0)
		conv.str[conv.len - 1] = '\0';
	write_percent(spec, &conv, buf);
	free(conv.str);
}
