/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:20:34 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/23 21:07:16 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

/*
** The ft_string_init() function alloactes a t_string of size
** FT_STRING_SIZE (defined in libft.h).
** Setting the first byte to '\0'. The rest is uninitialized.
**
** On success, returns a pointer the allocated string.
** On error, returns NULL.
*/

t_string		*ft_string_init(void)
{
	t_string *string;

	if ((string = malloc(sizeof *string)) == NULL)
		return (NULL);
	if ((string->buf = malloc(sizeof *string->buf * FT_STRING_SIZE)) == NULL)
		return (NULL);
	string->size = FT_STRING_SIZE;
	string->buf[0] = '\0';
	string->len = 0;
	return (string);
}
