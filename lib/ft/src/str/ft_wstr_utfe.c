/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_utfe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 21:38:32 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/30 02:47:43 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <wchar.h>

/*
** 110XXXXX 10XXXXXX
*/

static void		wchar_two(char **str, wchar_t c)
{
	uint8_t	byte;

	byte = 192 + ((c & 1984) >> 6);
	(*str)[0] = byte;
	byte = 128 + (c & 63);
	(*str)[1] = byte;
	*str += 2;
}

/*
** 1110XXXX 10XXXXXX 10XXXXXX
*/

static void		wchar_three(char **str, wchar_t c)
{
	uint8_t	byte;

	byte = 224 + ((c & 64440) >> 12);
	(*str)[0] = byte;
	byte = 128 + ((c & 4032) >> 6);
	(*str)[1] = byte;
	byte = 128 + (c & 63);
	(*str)[2] = byte;
	*str += 3;
}

/*
** 11110XXX 10XXXXXX 10XXXXXX 10XXXXXX
*/

static void		wchar_four(char **str, wchar_t c)
{
	uint8_t	byte;

	byte = 240 + ((c & 917504) >> 18);
	(*str)[0] = byte;
	byte = 128 + ((c & 126976) >> 12);
	(*str)[1] = byte;
	byte = 128 + ((c & 4032) >> 6);
	(*str)[2] = byte;
	byte = 128 + (c & 63);
	(*str)[3] = byte;
	*str += 4;
}

/*
** Converts a wchar string into a newly
** allocated UTF-8 encoded string.
** Returns the new string.
*/

char			*ft_wstr_utfe(wchar_t *str)
{
	char	*res;
	size_t	utfe_len;

	utfe_len = ft_wstr_utfelen(str);
	if ((res = ft_strnew(utfe_len)) == NULL)
		return (NULL);
	while (*str != '\0')
	{
		if (*str < 127)
		{
			*res = *str;
			++res;
		}
		else if (*str < 2048)
			wchar_two(&res, *str);
		else if (*str < 65536)
			wchar_three(&res, *str);
		else
			wchar_four(&res, *str);
		++str;
	}
	*res = '\0';
	res -= utfe_len;
	return (res);
}
