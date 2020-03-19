/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array2_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:48:45 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/23 19:42:49 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
#include <stdlib.h>

/*
** The ft_array2_remove() function removes the element of index _index_
** of the t_array _array_ shifting the rest of the elements back.
** If _index_ is greater than the length of the array, nothing happens.
**
** Does not return.
**
** SEE ALSO:
** 		ft_array2_pop
*/

void	ft_array2_remove(t_array2 *array, size_t index)
{
	if (index >= array->len)
		return ;
	while (index < array->len)
	{
		array->arr[index] = array->arr[index + 1];
		index++;
	}
	--array->len;
	array->arr[array->len] = NULL;
}
