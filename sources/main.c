/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 09:44:44 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/14 22:19:13 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int ac, char **av)
{
	(void)ac;(void)av;
	t_farm	farm;

	/*
	if (--ac == 0)
		print_help();
	*/
	initialize_farm(&farm);
	if (parse_input(&farm) == FAILURE)
		ft_perror_exit("ERROR");
	return (SUCCESS);
}
