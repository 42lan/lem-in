/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:17:08 by abaisago          #+#    #+#             */
/*   Updated: 2019/04/19 16:18:38 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_printerr_fd(int fd, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	ft_vdprintf(fd, fmt, ap);
	exit(1);
}
