/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:34:31 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/11 13:56:45 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_utils.h"
#include <string.h>
#include <stdint.h>

size_t	get_cast_arg(va_list ap, char size)
{
	size_t	nbr;

	if (size == SIZE_LL)
		nbr = (long long)va_arg(ap, size_t);
	else if (size == SIZE_Z)
		nbr = (size_t)va_arg(ap, size_t);
	else if (size == SIZE_HH)
		nbr = (char)va_arg(ap, size_t);
	else if (size == SIZE_H)
		nbr = (short)va_arg(ap, size_t);
	else if (size == SIZE_L)
		nbr = (long)va_arg(ap, size_t);
	else if (size == SIZE_J)
		nbr = (uintmax_t)va_arg(ap, size_t);
	else
		nbr = (int)va_arg(ap, size_t);
	return (nbr);
}

size_t	get_cast_arg_unsigned(va_list ap, char size)
{
	size_t	nbr;

	if (size == SIZE_LL)
		nbr = (unsigned long long)va_arg(ap, size_t);
	else if (size == SIZE_Z)
		nbr = (size_t)va_arg(ap, size_t);
	else if (size == SIZE_HH)
		nbr = (unsigned char)va_arg(ap, size_t);
	else if (size == SIZE_H)
		nbr = (unsigned short)va_arg(ap, size_t);
	else if (size == SIZE_L)
		nbr = (unsigned long)va_arg(ap, size_t);
	else if (size == SIZE_J)
		nbr = (uintmax_t)va_arg(ap, size_t);
	else
		nbr = (unsigned int)va_arg(ap, size_t);
	return (nbr);
}
