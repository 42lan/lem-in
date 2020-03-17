/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:30:50 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/09 10:20:22 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	cycle(intmax_t nbr, int fd)
{
	if (nbr >= 10)
	{
		cycle(nbr / 10, fd);
		cycle(nbr % 10, fd);
	}
	else
		ft_putchar_fd('0' + nbr, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	intmax_t	nbr;

	nbr = n;
	if (ft_abs_is(&nbr))
		ft_putchar_fd('-', fd);
	cycle(nbr, fd);
}
