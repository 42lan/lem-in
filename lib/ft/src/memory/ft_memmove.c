/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:24:48 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/09 13:55:29 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src == dst)
		return (dst);
	if (src - dst > 0)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
	return (dst);
}
