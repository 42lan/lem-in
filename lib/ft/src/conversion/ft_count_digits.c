/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:08:46 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/11 16:35:57 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdint.h>

/*
** Counts the number of digits and the
** negative sign of any signed integer.
*/

size_t	ft_count_digits(intmax_t n, uint8_t base)
{
	size_t	cnt;

	if (n == 0)
		return (1);
	cnt = 0;
	if (n < 0)
		cnt = 1;
	while (n != 0)
	{
		n /= base;
		++cnt;
	}
	return (cnt);
}
