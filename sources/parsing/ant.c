/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 17:22:27 by abaisago          #+#    #+#             */
/*   Updated: 2020/06/03 03:59:51 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include "tools.h"
#include "lib.h"

unsigned		get_ants(void)
{
	long long	ants;
	char		*line;
	char		*p_line;

	readline(&line, 0);
	p_line = line;
	ants = ft_atoll(line);
	if (overflowed(line, ants) == SUCCESS)
		ft_printerr(E_ANTS);
	line += ft_strspn(line, "0123456789 \t");
	if (*line != '\0')
		ft_printerr(E_NONDIG);
	ft_strdel(&p_line);
	return (ants);
}
