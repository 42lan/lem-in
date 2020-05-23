/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:34:27 by abaisago          #+#    #+#             */
/*   Updated: 2020/05/11 15:39:07 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
#include <stdlib.h>

/*
** The ft_string_resize() changes the size of the memory block pointed
** to by the member variable buf of _string_, copying the old memory
** space over up to the minimun of the old _string_->len
** and new _size_ - 1 (for the null terminating byte),
** setting the size and length accordingly.
**
** If _string_->buf is NULL, it will simply allocate a t_string of size
** _size_ and length 0.
**
** If _size_ is 0, then the call is equivalent to malloc(size). If
** _string_->buf is not NULL, the poniter will still be freed.
**
** On success, returns a pointer to the allocated t_string.
** On error, return a NULL pointer.
*/

t_string	*ft_string_resize(t_string *string, size_t size)
{
	char	*old;

	old = string->buf;
	if ((string->buf = malloc(sizeof(*string->buf) * size)) == NULL)
		return (NULL);
	string->size = size;
	if (old == NULL)
	{
		string->len = 0;
		return (string);
	}
	else if (size > string->len)
		ft_memcpy(string->buf, old, string->len + 1);
	else
	{
		ft_memcpy(string->buf, old, size - 1);
		string->len = size - 1;
		string->buf[string->len] = '\0';
	}
	ft_strdel(&old);
	return (string);
}
