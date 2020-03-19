/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:24:56 by abosch            #+#    #+#             */
/*   Updated: 2019/04/01 22:03:28 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "integers.h"
#include "output.h"
#include "percent.h"
#include "type_utils.h"

#include <stdlib.h>
#include <string.h>

void	type_di(va_list ap, t_spec *spec, t_buf *buf)
{
	t_str		conv;
	intmax_t	nbr;
	char		str[21];

	nbr = get_cast_arg(ap, spec->size);
	conv.str = ft_llitosa_base(nbr, 10, str);
	if (nbr < 0)
	{
		++conv.str;
		spec->flags |= F_NEG;
	}
	if (spec->flags & F_QUOTE)
		conv.str = nbr_grouping(&conv, ',', 3);
	conv.len = ft_strlen(conv.str);
	spec->flags &= ~F_HASH;
	if (spec->flags & F_PRECI && nbr == 0)
		conv.len = 0;
	if (spec->flags & F_PRECI)
		spec->flags &= ~F_ZERO;
	write_percent(spec, &conv, buf);
	if (spec->flags & F_NEG)
		--conv.str;
	if (spec->flags & F_QUOTE)
		free(conv.str);
}

void	type_u(va_list ap, t_spec *spec, t_buf *buf)
{
	t_str		conv;
	size_t		nbr;
	char		str[21];

	nbr = get_cast_arg_unsigned(ap, spec->size);
	conv.str = ft_lluitosa_base(nbr, 10, str);
	conv.len = ft_strlen(conv.str);
	if (spec->flags & F_QUOTE)
		conv.str = nbr_grouping(&conv, ',', 3);
	spec->flags &= ~(F_HASH | F_PLUS | F_BLANK);
	if (spec->flags & F_PRECI)
	{
		if (nbr == 0)
			conv.len = 0;
		spec->flags &= ~F_ZERO;
	}
	write_percent(spec, &conv, buf);
	if (spec->flags & F_QUOTE)
		free(conv.str);
}
