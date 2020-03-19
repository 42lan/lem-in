/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 21:25:33 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/14 19:44:32 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int power)
{
	int		res;

	res = nb;
	if (power == 0)
		res = 1;
	else if (power < 0)
		res = 0;
	power--;
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}
