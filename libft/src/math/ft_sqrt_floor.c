/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 01:46:07 by abaisago          #+#    #+#             */
/*   Updated: 2018/12/12 12:26:29 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt_floor(int nb)
{
	long long int	res;

	if (nb < 0)
		return (0);
	res = nb / 3 + 1;
	while (res * res > nb)
		res = (nb / res + res) / 2;
	return (res);
}
