/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array2_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 22:13:13 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/23 19:37:48 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>
#include <stdlib.h>

/*
** The ft_array2_new() function alloactes a t_array2 of size _size_.
** Sets the first element of the array to NULL, the rest is initialised.
**
** On success, returns a pointer to the allocated t_array2
** On error, returns NULL.
*/

t_array2	*ft_array2_new(size_t size)
{
	t_array2 *array;

	if ((array = malloc(sizeof(*array))) == NULL)
		return (NULL);
	if ((array->arr = malloc(sizeof(array->arr) * (size + 1))) == NULL)
		return (NULL);
	array->size = size;
	array->len = 0;
	return (array);
}
