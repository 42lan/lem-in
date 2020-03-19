/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:41:45 by abosch            #+#    #+#             */
/*   Updated: 2019/04/19 15:19:58 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "output.h"

#include <string.h>
#include <unistd.h>

void	print_buf(t_buf *buf)
{
	write(buf->fd, buf->data, buf->index);
	buf->index = 0;
}

void	write_char(t_buf *buf, char c, size_t len)
{
	size_t	i;

	buf->read += len;
	i = -1;
	while (++i < len)
	{
		buf->data[buf->index] = c;
		++buf->index;
		if (buf->index == BUFF_SIZE)
		{
			print_buf(buf);
			buf->index = 0;
		}
	}
}

void	write_str(t_buf *buf, char *str, size_t len)
{
	size_t	i;

	buf->read += len;
	i = -1;
	while (++i < len)
	{
		buf->data[buf->index] = str[i];
		buf->index++;
		if (buf->index == BUFF_SIZE)
		{
			print_buf(buf);
			buf->index = 0;
		}
	}
}
