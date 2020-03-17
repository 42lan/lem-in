/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array2_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:40:08 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/23 19:02:49 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

/*
** The ft_array2_del() function frees the pointer
** to t_array2 pointed to by _address_ and sets it
** to NULL as well as it's length and size to 0.
**
** Does not return.
*/

void	ft_array2_del(t_array2 **address)
{
	t_array2	*array = *address;

	free(array->arr);
	array->arr = NULL;
	array->len = 0;
	array->size = 0;
	*address = NULL;
}
