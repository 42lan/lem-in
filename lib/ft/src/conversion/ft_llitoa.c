/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:02:17 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/12 17:50:49 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdint.h>

/*
** Returns an allocated representation string of a
** 64-bit signed integer in a specified base of up to 36.
*/

char			*ft_llitoa(int64_t n)
{
	size_t		i;
	char		*res;

	if (n < 0 && n - 1 > 0)
		return (ft_strdup("-9223372036854775808"));
	if ((res = (char*)ft_strnew(ft_count_digits(n, 10))) == NULL)
		return (NULL);
	i = 0;
	if (ft_abs_is((intmax_t*)&n))
	{
		res[0] = '-';
		i = 1;
	}
	ft_getnbr_base(n, 10, res, &i);
	return (res);
}
