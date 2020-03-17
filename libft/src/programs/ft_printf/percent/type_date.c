/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_date.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 18:29:02 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/27 21:07:51 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "date.h"
#include "libft.h"

#include "output.h"
#include "percent.h"

#include <stdlib.h>

static char		*get_date(t_date date, char *iso)
{
	char year[5];
	char month[3];
	char day[3];

	ft_llitosa_base(date.year, 10, year);
	ft_llitosa_base(date.month, 10, month);
	ft_llitosa_base(date.day, 10, day);
	ft_strcpy(iso, year);
	iso[4] = '-';
	ft_strcpy(iso + 5, month);
	iso[7] = '-';
	ft_strcpy(iso + 8, day);
	iso[11] = '\0';
	return (iso);
}

void			type_k(va_list ap, t_spec *spec, t_buf *buf)
{
	char		*iso;
	t_str		conv;
	t_date		date;

	date.year = va_arg(ap, unsigned int);
	date.month = va_arg(ap, unsigned int);
	date.day = va_arg(ap, unsigned int);
	if (date.year > 9999 || date.month > 12 || date.day > 31)
		return ;
	if ((iso = ft_strnew(10)) == NULL)
		return ;
	conv.str = get_date(date, iso);
	conv.len = 10;
	spec->flags = 0;
	write_percent(spec, &conv, buf);
	free(iso);
}
