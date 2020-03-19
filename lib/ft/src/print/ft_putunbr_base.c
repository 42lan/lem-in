/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 22:52:54 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/16 19:21:25 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int		wrong_chars_repeat(char *base, size_t len)
{
	size_t	c;
	size_t	i;

	c = 0;
	while (c < len)
	{
		i = 0;
		while (i < len)
		{
			if (base[c] == base[i] && c != i)
				return (1);
			i++;
		}
		c++;
	}
	i = 0;
	while (i < len)
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

static int		has_errors(char *base, size_t len)
{
	if (len < 2)
		return (1);
	if (wrong_chars_repeat(base, len))
		return (1);
	return (0);
}

void			ft_putunbr_base(unsigned int nbr, char *base)
{
	size_t			i;
	unsigned int	len;
	uintmax_t		nb;
	int				res[32];

	nb = nbr;
	len = ft_strlen(base);
	if (has_errors(base, len))
		return ;
	i = 0;
	while (nb >= len)
	{
		res[32 - i] = nb % len;
		nb /= len;
		i++;
	}
	res[32 - i] = nb;
	while (i != 0)
	{
		ft_putchar(base[res[32 - i]]);
		i--;
	}
	ft_putchar(base[res[32 - i]]);
}
