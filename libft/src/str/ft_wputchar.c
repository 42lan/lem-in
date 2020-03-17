/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 20:17:01 by abaisago          #+#    #+#             */
/*   Updated: 2019/03/15 21:31:01 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <wchar.h>

static void		wchar_two(wchar_t c)
{
	unsigned char one;
	unsigned char two;

	one = 192 + ((c & 1984) >> 6);
	two = 128 + (c & 63);
	write(1, &one, 1);
	write(1, &two, 1);
}

static void		wchar_three(wchar_t c)
{
	unsigned char one;
	unsigned char two;
	unsigned char three;

	one = 224 + ((c & 64440) >> 12);
	two = 128 + ((c & 4032) >> 6);
	three = 128 + (c & 63);
	write(1, &one, 1);
	write(1, &two, 1);
	write(1, &three, 1);
}

static void		wchar_four(wchar_t c)
{
	unsigned char one;
	unsigned char two;
	unsigned char three;
	unsigned char four;

	one = 240 + ((c & 917504) >> 18);
	two = 128 + ((c & 126976) >> 12);
	three = 128 + ((c & 4032) >> 6);
	four = 128 + (c & 63);
	write(1, &one, 1);
	write(1, &two, 1);
	write(1, &three, 1);
	write(1, &four, 1);
}

void			ft_wputchar(wchar_t c)
{
	if (c < 127)
		write(1, &c, 1);
	else if (c < 2048)
		wchar_two(c);
	else if (c < 65536)
		wchar_three(c);
	else
		wchar_four(c);
}
