/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:32:34 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/23 21:10:37 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>

/*
** The ft_string_insert() function inserts the string _text_ into the
** t_string _string_ at indexition _index_, re-allocating and shifting
** memory as needed.
** If _text_ is NULL, the text '(null)' will be inserted instead.
**
** Does not return.
*/

void	ft_string_insert(t_string *string, const char *text, size_t index)
{
	size_t		len;
	size_t		new_len;
	unsigned	mult;

	if (text == NULL)
		text = "(null)";
	len = ft_strlen(text);
	if (index > string->len)
		index = string->len;
	new_len = string->len + len + 1;
	if (new_len > string->size)
	{
		mult = (new_len - string->size) / FT_STRING_INC + 1;
		ft_string_resize(string, string->size + FT_STRING_INC * mult);
	}
	ft_memmove(
		string->buf + index + len,
		string->buf + index,
		string->len - index + 1);
	string->len += len;
	ft_memcpy(string->buf + index, text, len);
	string->buf[string->len] = '\0';
}
