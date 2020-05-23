/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array2_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:02:25 by abaisago          #+#    #+#             */
/*   Updated: 2020/05/11 15:31:43 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
#include <stdlib.h>

/*
** The ft_array2_resize() changes the size of the memory block pointed
** to by _array_, copying the old memory space over up to the minimun of
** the old _array_->len and new _size_ - 1 (for the NULL terminating
** address), setting the size and length accordingly.
**
** If _array_->arr is NULL, it will simply allocate a t_array of size
** _size_ and length 0.
**
** If _size_ is 0, then the call is equivalent to malloc(size). If
** _array_->arr is not NULL, the poniter will still be freed.
**
** On success, returns a pointer to the allocated t_array.
** On error, return a NULL pointer.
*/

t_array2	*ft_array2_resize(t_array2 *array, size_t size)
{
	void	**old;

	old = array->arr;
	if ((array->arr = malloc(sizeof(*array->arr) * size)) == NULL)
		return (NULL);
	array->size = size;
	if (old == NULL)
	{
		array->len = 0;
		return (array);
	}
	else if (size > array->len)
		ft_memcpy(array->arr, old, sizeof(*array->arr) * (array->len + 1));
	else
	{
		ft_memcpy(array->arr, old, sizeof(*array->arr) * (size - 1));
		array->len = size - 1;
		array->arr[array->len] = NULL;
	}
	ft_memdel((void**)&old);
	return (array);
}
