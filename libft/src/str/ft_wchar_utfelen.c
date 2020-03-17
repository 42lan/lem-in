/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_utfelen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 11:15:37 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/30 02:38:22 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

/*
** Computes the necessary lenth in bytes that
** a wchar character would need in UTF-8 encoding.
*/

int8_t	ft_wchar_utfelen(wchar_t c)
{
	if (c < 127)
		return (1);
	else if (c < 2048)
		return (2);
	else if (c < 65536)
		return (3);
	else
		return (4);
}
