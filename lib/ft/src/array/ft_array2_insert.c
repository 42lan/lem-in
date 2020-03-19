/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array2_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:06:20 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/23 19:23:34 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
#include <stdlib.h>

/*
** The ft_array2_insert() function inserts the array _elem_ into the
** t_array _array_ at index _index_, re-allocating and shifting
** memory as needed.
** If _elem_ is NULL, nothing happens.
** IF _index_ is greater than the length of the array, _elem_ is
** appended to the end of the array.
**
** Does not return.
*/

void	ft_array2_insert(t_array2 *array, void *elem, size_t index)
{
	size_t	i;

	if (elem == NULL)
		return ;
	if (index > array->len)
		index = array->len;
	if (array->len >= array->size)
		ft_array2_resize(array, array->size + FT_ARRAY_INC);
	i = array->len;
	while (i > index)
	{
		array->arr[i + 1] = array->arr[i];
		--i;
	}
	array->arr[i + 1] = array->arr[i];
	array->arr[index] = elem;
	++array->len;
}
