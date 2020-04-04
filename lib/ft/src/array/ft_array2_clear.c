/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array2_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:44:52 by abaisago          #+#    #+#             */
/*   Updated: 2020/04/04 13:31:24 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>

void	ft_array2_clear(t_array2 *array)
{
	size_t	i;

	i = -1;
	while (++i < array->size)
		array->arr = NULL;
	array->len = 0;
	array->size = 0;
}
