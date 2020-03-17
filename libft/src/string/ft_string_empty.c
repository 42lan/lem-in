/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_empty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:05:32 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/25 14:42:49 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>

/*
** The ft_string_empty() function will set the first byte of the
** t_string _string_ to null and the length to 0.
**
** Does not return.
*/

void	ft_string_empty(t_string *string)
{
	string->buf[0] = '\0';
	string->len = 0;
}
