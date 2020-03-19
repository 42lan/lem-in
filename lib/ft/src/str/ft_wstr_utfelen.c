/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_utfelen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 11:15:37 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/30 02:39:11 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
** Computes the necessary lenth in bytes that
** a wchar string would need in UTF-8 encoding.
*/

size_t	ft_wstr_utfelen(wchar_t *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str < 127)
			++i;
		else if (*str < 2048)
			i += 2;
		else if (*str < 65536)
			i += 3;
		else
			i += 4;
		++str;
	}
	return (i);
}
