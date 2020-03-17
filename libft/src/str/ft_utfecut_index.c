/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utfecut_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 12:33:33 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/16 13:32:50 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <strings.h>

size_t	ft_utfecut_index(char *str, size_t len)
{
	size_t	i;
	size_t	last;

	i = 1;
	last = 0;
	while (len > 0 && str[i] != '\0')
	{
		if ((str[i] & 192) != 128)
			last = i;
		--len;
		++i;
	}
	return (last);
}
