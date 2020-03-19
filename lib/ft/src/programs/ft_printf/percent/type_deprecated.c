/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_deprecated.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 03:00:37 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/30 03:10:24 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "percent.h"

void	type_dd(va_list ap, t_spec *spec, t_buf *buf)
{
	spec->size = SIZE_L;
	type_di(ap, spec, buf);
}

void	type_oo(va_list ap, t_spec *spec, t_buf *buf)
{
	spec->size = SIZE_L;
	type_o(ap, spec, buf);
}

void	type_uu(va_list ap, t_spec *spec, t_buf *buf)
{
	spec->size = SIZE_L;
	type_u(ap, spec, buf);
}
