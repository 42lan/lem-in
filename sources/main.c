/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 09:44:44 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/21 10:39:13 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		lemin(int ac, char **av)
{
	t_farm	farm;

	initialization(&farm);
	if (parse_input(&farm) == FAILURE)
		exit(EXIT_FAILURE);
	return (SUCCESS);
}

int		main(int ac, char **av)
{
	return (lemin(ac, av));
}
