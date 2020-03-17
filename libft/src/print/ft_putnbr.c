/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 06:58:38 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/09 10:18:32 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static	void	cycle(intmax_t nbr)
{
	if (nbr >= 10)
	{
		cycle(nbr / 10);
		cycle(nbr % 10);
	}
	else
		ft_putchar('0' + nbr);
}

void			ft_putnbr(int n)
{
	intmax_t		nbr;

	nbr = n;
	if (ft_abs_is(&nbr))
		ft_putchar('-');
	cycle(nbr);
}
