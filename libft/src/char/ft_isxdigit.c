/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:22:38 by abaisago          #+#    #+#             */
/*   Updated: 2018/11/14 12:31:26 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isxdigit(int c)
{
	return ((c >= '0' && c <= '9')
			|| (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}
