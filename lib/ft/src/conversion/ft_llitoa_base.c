/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:49:11 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/12 17:36:28 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*
** Returns an allocated representation string of a
** 64-bit signed integer in a specified base of up to 36.
*/

char			*ft_llitoa_base(int64_t value, uint8_t base)
{
	size_t		at;
	char		*res;

	if (base > 36)
		return (NULL);
	if (value < 0 && value - 1 > 0 && base == 10)
		return (ft_strdup("-9223372036854775808"));
	if ((res = (char*)ft_strnew(1 + ft_count_digits(value, base))) == NULL)
		return (NULL);
	at = 0;
	if (ft_abs_is((intmax_t*)&value) && base == 10)
	{
		res[0] = '-';
		at = 1;
	}
	ft_getnbr_base(value, base, res, &at);
	res[at] = '\0';
	return (res);
}
