/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 20:54:45 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/25 17:55:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "parsing.h"

#include <errno.h>
#include <stddef.h>
#include <string.h>

void		inc_links(t_list *hmap, char *line)
{
	(void)hmap; (void)line;
/*
	int		i1;
	int		i2;
	char	*r1;
	char	*r2;
	t_list	*links;

	if (!(links = ft_list_init()))
		ft_printerr("lem-in: inc_links(malloc): %s\n", strerror(errno));
	if (ft_strchr(line, '-'))
	{
		r1 = ft_strtok(line, "-");
		ft_printf("r1: %s\n", r1);
		r2 = ft_strtok(NULL, "-");
		i1 = hmap_index(r1);
		ft_printf("i1: %d\n", i1);
		i2 = hmap_index(r2);
		ft_printf(": %s\n", hmap[i1].room->name);
	}
*/
}

void		get_links(t_list *hmap, char *line)
{
	int		ret;

	if (line[0] == '#')
		ft_strdel(&line);
	else
	{
		inc_links(hmap, line);
		ft_strdel(&line);
	}
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (line[0] == '#')
			continue ;
		inc_links(hmap, line);
		ft_strdel(&line);
	}
}
