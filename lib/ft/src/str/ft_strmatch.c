/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 19:21:32 by abaisago          #+#    #+#             */
/*   Updated: 2019/04/01 17:31:58 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int8_t		ft_strmatch(char *match, char *str)
{
	size_t	i;

	i = 0;
	while (match[i] != '\0')
	{
		if (match[i] != str[i])
			return (0);
		++i;
	}
	return (1);
}
