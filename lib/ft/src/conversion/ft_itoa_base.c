/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:49:11 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/12 17:39:06 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*
** Takes an int and outputs it's allocated
** string representation in a specified base.
** Does not print negative value for bases other than 10.
*/

char			*ft_itoa_base(int value, uint8_t base)
{
	size_t		at;
	intmax_t	n;
	char		*res;

	res = (char*)malloc(sizeof(*res) * (33));
	at = 0;
	n = value;
	if (ft_abs_is(&n) && base == 10)
	{
		res[at] = '-';
		++at;
	}
	ft_getnbr_base(n, base, res, &at);
	res[at] = '\0';
	return (res);
}
