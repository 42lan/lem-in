/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 16:39:21 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/11 16:35:45 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdint.h>

/*
** Takes in a positive 'value' and copies it's
** base representation (2 to 36) into 'res'.
*/

void	ft_getnbr_base(size_t value, uint8_t base, char *str, size_t *index)
{
	if (value >= base)
	{
		ft_getnbr_base(value / base, base, str, index);
		ft_getnbr_base(value % base, base, str, index);
	}
	else if (value <= 9)
	{
		str[*index] = '0' + value;
		(*index)++;
	}
	else
	{
		str[*index] = 'a' + value - 10;
		(*index)++;
	}
}
