/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:02:17 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/11 15:57:58 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static	void	fill_string(intmax_t nbr, char *str, size_t *i)
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
** Takes an int and outpus it's allocated string representation.
*/

char			*ft_itoa(intmax_t n)
{
	size_t		i;
	char		*res;

	i = 0;
	res = (char*)ft_strnew(ft_count_digits(n, 10));
	if (res == NULL)
		return (NULL);
	if (ft_abs_is(&n))
		res[i++] = '-';
	fill_string(n, res, &i);
	return (res);
}
