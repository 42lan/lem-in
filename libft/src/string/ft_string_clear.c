/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:56:59 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/25 14:41:57 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>

/*
** The ft_string_clear() function will set every byte of the
** t_string _string_ to null and the length to 0.
**
** Does not return.
*/

void	ft_string_clear(t_string *string)
{
	size_t	i;

	i = -1;
	while (++i < string->size)
		string->buf[i] = '\0';
	string->len = 0;
}
