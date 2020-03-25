/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 09:44:44 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/25 19:19:36 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "parsing.h"

int		lemin(int ac, char **av)
{
	t_farm	farm;
	t_list	hmap[HMAP_SIZE];

	if (parse_input(&farm, hmap) == FAILURE)
		exit(EXIT_FAILURE);
	return (SUCCESS);
}

int		main(int ac, char **av)
{
	return (lemin(ac, av));
}
