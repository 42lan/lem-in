/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lluitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:49:11 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/11 16:35:22 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*
** Returns an allocated string representation of an
** 64-bii unsigned integer in a specified base of up to 36.
*/

char			*ft_lluitoa_base(uint64_t value, uint8_t base)
{
	size_t		i;
	char		*res;

	res = (char*)malloc(sizeof(*res) * (ft_count_udigits(value, base) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	ft_getnbr_base(value, base, res, &i);
	res[i] = '\0';
	return (res);
}
