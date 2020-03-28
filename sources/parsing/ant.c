/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 17:22:27 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/28 17:39:26 by abaisago         ###   ########.fr       */
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

	if (get_next_line(0, &line) < 0)
		ft_printerr("lem-in: get_ants(read): %s\n", strerror(errno));
	ants = ft_atoll(line);
	if (overflowed(line, ants))
		ft_printerr(ERROR);
	line += ft_strskip(line, ft_isdigit);
	line += ft_strskip_set(line, " \t");
	if (*line != '\0')
		ft_printerr(ERROR);
	return (ants);
}

