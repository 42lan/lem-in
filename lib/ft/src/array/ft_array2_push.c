/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array2_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:15:20 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/23 18:43:44 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_array2_push() function appends the array _elem_ to the
** t_array2 _array_ re-allocating memory as needed.
** If _elem_ is NULL, nothing happens.
**
** Does not return.
*/

void	ft_array2_push(t_array2 *array, void *elem)
{
	if (elem == NULL)
		return ;
	if (array->len >= array->size)
		ft_array2_resize(array, array->size + FT_ARRAY_INC);
	array->arr[array->len] = elem;
	++array->len;
	array->arr[array->len] = NULL;
}
