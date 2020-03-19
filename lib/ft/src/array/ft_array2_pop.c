/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array2_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:38:00 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/23 18:40:44 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

#include <stddef.h>
#include <stdlib.h>

/*
** The ft_array2_pop() function removes the last element of
** the t_array _array_.
**
** Does not return.
**
** SEE ALSO:
** 		ft_array2_remove
*/

void	ft_array2_pop(t_array2 *array)
{
	ft_array2_remove(array, array->len - 1);
}
