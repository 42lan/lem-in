/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array2_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:59:51 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/23 19:03:50 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <stddef.h>

/*
** The ft_array2_init() function alloactes a t_array2 of size
** FT_ARRAY_SIZE (defined in libft.h).
** Sets the first element of the array to NULL, the rest is initialised.
**
** On success, returns a pointer to the allocated t_array2
** On error, returns NULL.
*/

t_array2	*ft_array2_init(void)
{
	t_array2 *array;

	if ((array = malloc(sizeof(*array))) == NULL)
		return (NULL);
	if ((array->arr = malloc(sizeof(*array->arr) * FT_ARRAY_SIZE)) == NULL)
		return (NULL);
	array->arr[0] = NULL;
	array->size = FT_ARRAY_SIZE;
	array->len = 0;
	return (array);
}
