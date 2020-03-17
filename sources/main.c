/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 09:44:44 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/17 11:46:59 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int ac, char **av)
{
	(void)ac;(void)av;
	t_data	data;

	initialization(&data);
	if (parse_input(&data) == FAILURE)
	{
		if (EMF)
			ft_printerr("parsing() failed in main()\n");
		exit(EXIT_FAILURE);
	}
	return (SUCCESS);
}
