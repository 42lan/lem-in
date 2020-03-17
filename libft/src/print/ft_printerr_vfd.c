/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr_vfd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:18:18 by abaisago          #+#    #+#             */
/*   Updated: 2019/04/19 16:18:25 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_printerr_vfd(int fd, const char *fmt, va_list ap)
{
	ft_vdprintf(fd, fmt, ap);
	exit(1);
}
