/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 17:22:27 by abaisago          #+#    #+#             */
/*   Updated: 2020/04/19 21:14:26 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
#include "lib.h"

#include "predicates.h"

#include <errno.h>
#include <string.h>

unsigned	get_ants(void)
{
	char		*line;
	char		*p_line;
	long long	ants;
	int			ret;

	if ((ret = get_next_line(0, &line)) < 0)
		ft_printerr("lem-in: get_ants(read): %s\n", strerror(errno));
	if (ret == 0)
		ft_printerr(ERROR);
	p_line = line;
	ants = ft_atoll(line);
	if (overflowed(line, ants))
		ft_printerr(E_ANTS);
	line += ft_strspn(line, "0123456789 \t");
	if (*line != '\0')
		ft_printerr(E_NONDIG);
	ft_strdel(&p_line);
	return (ants);
}
