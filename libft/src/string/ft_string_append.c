/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:26:32 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/23 21:05:20 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>

/*
** The ft_string_append() function appends the string _text_to the
** t_string _string_ re-allocating memory as needed.
** If _text_ is NULL, the text '(null)' will be appended instead.
**
** Does not return.
*/

void	ft_string_append(t_string *string, const char *text)
{
	size_t		len;
	size_t		new_len;
	unsigned	mult;

	if (text == NULL)
		text = "(null)";
	len = ft_strlen(text);
	new_len = string->len + len + 1;
	if (new_len > string->size)
	{
		mult = (new_len - string->size) / FT_STRING_INC + 1;
		ft_string_resize(string, string->size + FT_STRING_INC * mult);
	}
	string->len += len;
	ft_strcat(string->buf, text);
}
