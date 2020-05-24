/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 17:22:27 by abaisago          #+#    #+#             */
/*   Updated: 2020/05/24 23:28:12 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include "tools.h"
#include "lib.h"

unsigned		get_ants(void)
{
	char		*line;
	char		*p_line;
	long long	ants;

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
