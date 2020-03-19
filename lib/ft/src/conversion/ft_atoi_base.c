/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 21:40:10 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/30 02:37:52 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <string.h>

static int		wrong_chars_repeat(char *base, size_t base_len)
{
	size_t	c;
	size_t	i;

	c = 0;
	while (c < base_len)
	{
		i = 0;
		while (i < base_len)
		{
			if (base[c] == base[i] && c != i)
				return (1);
			i++;
		}
		c++;
	}
	i = 0;
	while (i < base_len)
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		if (base[i] < 32 || base[i] > 126)
			return (1);
		i++;
	}
	return (0);
}

static int		is_in_base(char c, char *base)
{
	size_t	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static void		signs(char *str, size_t *i, int8_t *sign)
{
	if (str[*i] == '-' || str[*i] == '+')
		i++;
	if (str[*i] == '-')
		*sign = -1;
}

int				ft_atoi_base(char *str, char *base)
{
	size_t		i;
	int			num;
	int8_t		sign;
	size_t		base_len;
	size_t		str_len;

	i = 0;
	num = 0;
	sign = 1;
	base_len = ft_strlen(base);
	str_len = ft_strlen(str);
	if (base_len < 2 || str_len == 0 || wrong_chars_repeat(base, base_len))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	signs(str, &i, &sign);
	while (is_in_base(str[i], base) != -1)
	{
		num = num * base_len + is_in_base(str[i], base);
		if (num < 0)
			return (0);
		i++;
	}
	return (num * sign);
}
