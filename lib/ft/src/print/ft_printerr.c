/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:01:40 by abaisago          #+#    #+#             */
/*   Updated: 2020/01/22 16:06:31 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_printerr(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	ft_vdprintf(2, fmt, ap);
	exit(1);
}
