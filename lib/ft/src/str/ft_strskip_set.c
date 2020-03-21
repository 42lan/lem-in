/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskip_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 11:16:59 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/21 11:33:14 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
** Iterates over the string (s) while it's characters
** are equal to one of the characters in (set).
** The intent is to skip certain characters of a string.
** Could also be used to count them.
**
** Returns the amount of skipped characters.
*/

size_t	ft_strskip_set(const char *s, char *set)
{
	size_t	i;

	i = 0;
	while (ft_isset(s[i], set) && s[i] != '\0')
		++i;
	return (i);
}
