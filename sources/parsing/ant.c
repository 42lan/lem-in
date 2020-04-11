/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 17:22:27 by abaisago          #+#    #+#             */
/*   Updated: 2020/04/11 23:42:46 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

#include "predicates.h"

#include <errno.h>
#include <string.h>

unsigned	get_ants()
{
	char		*line;
	long long	ants;
	int			ret;

	if ((ret = get_next_line(0, &line)) < 0)
		ft_printerr("lem-in: get_ants(read): %s\n", strerror(errno));
	if (ret == 0)
		ft_printerr(ERROR);
	ants = ft_atoll(line);
	if (overflowed(line, ants))
		ft_printerr(E_ANTS);
	line += ft_strskip(line, ft_isdigit);
	line += ft_strskip_set(line, " \t");
	if (*line != '\0')
		ft_printerr(E_NONDIG);
	return (ants);
}

