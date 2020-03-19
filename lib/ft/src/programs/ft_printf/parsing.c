/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:26:45 by abaisago          #+#    #+#             */
/*   Updated: 2019/04/19 15:26:57 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

#include "curly.h"
#include "percent.h"

#include <unistd.h>

static void		choose(va_list og, va_list ap, char **fmt, t_buf *buf)
{
	if (**fmt == '%')
		percent(og, ap, fmt, buf);
	else if ((*fmt)[1] == '{')
	{
		++(*fmt);
		buf->data[buf->index++] = **fmt;
		buf->read += 1;
	}
	else if (**fmt == '{')
		curly(fmt, buf);
}

int				parsing(int fd, char *fmt, va_list ap)
{
	va_list		og;
	t_buf		buf;

	buf.index = 0;
	buf.read = 0;
	buf.fd = fd;
	va_copy(og, ap);
	while (*fmt != '\0')
	{
		if (buf.index == BUFF_SIZE)
			print_buf(&buf);
		if (*fmt != '%' && *fmt != '{')
		{
			buf.data[buf.index++] = *fmt;
			buf.read += 1;
		}
		else
			choose(og, ap, &fmt, &buf);
		++fmt;
	}
	write(buf.fd, buf.data, buf.index);
	return (buf.read);
}
