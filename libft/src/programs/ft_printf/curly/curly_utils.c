/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curly_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:47:33 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/28 16:53:05 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "curly_utils.h"

#include <string.h>

size_t	skip_to_colsing_curly(char **str)
{
	size_t	i;

	i = 0;
	while ((*str)[i] != '}' && (*str)[i] != '\0')
		++i;
	if ((*str)[i] == '\0')
		i = 0;
	return (i);
}
