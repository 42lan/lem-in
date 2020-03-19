/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lluitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:02:17 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/11 16:35:02 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdint.h>

static	void	fill_string(uint64_t nbr, char *str, size_t *i)
{
	if (nbr >= 10)
	{
		fill_string(nbr / 10, str, i);
		fill_string(nbr % 10, str, i);
	}
	else
	{
		str[*i] = nbr + '0';
		(*i)++;
	}
}

/*
** Return an allocated string representation of a
** 64-bit unsigned integer in a specified base of up to 36.
*/

char			*ft_lluitoa(uint64_t n)
{
	size_t		i;
	char		*res;

	i = 0;
	res = (char*)ft_strnew(ft_count_udigits(n, 10));
	if (res == NULL)
		return (NULL);
	fill_string(n, res, &i);
	return (res);
}
