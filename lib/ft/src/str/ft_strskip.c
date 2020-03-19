/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:03:23 by abaisago          #+#    #+#             */
/*   Updated: 2019/11/02 17:11:16 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

/*
** Parses the string (s) while the pointer to function (f) returns non-zero,
** the intent is to skip some characters int a string.
** Stops at character '\0' wether or not returns non-zero;
*/

size_t	ft_strskip(const char *s, int (*f)(int))
{
	size_t	i;

	i = 0;
	while ((*f)(s[i]) && s[i] != '\0')
		++i;
	return (i);
}
