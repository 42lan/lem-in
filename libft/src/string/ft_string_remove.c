/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:26:11 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/25 14:44:26 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
#include <stdlib.h>

/*
** The ft_string_remove() function sets to null, bytes from
** index [_index_] to index [_index_ + _size_] of the
** t_string _string_, shifting the rest of the bytes back.
**
** If _index_ is greater than the length of the string, nothing happens.
**
** If _index_ + _size_ is greater than the length of the string,
** the bytes will be set until the end of the string.
**
** Does not return.
*/

void	ft_string_remove(t_string *string, size_t index, size_t size)
{
	if (index >= string->len)
		return ;
	if (index + size > string->len)
		size = string->len - index;
	while (index + size < string->len)
	{
		string->buf[index] = string->buf[index + size];
		index++;
	}
	string->len -= size;
	string->buf[string->len] = '\0';
}
