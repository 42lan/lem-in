/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 09:32:10 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/16 21:37:08 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			print_line(void *content, size_t size, unsigned pos)
{
	(void)pos;
	return (ft_printf("[%s] %d\n", (char *)content, size));
}


int			parse_input(t_data *data, t_farm *farm)
{
	(void)farm;

	data->raw_input = save_raw_input();
	ft_list_print(data->raw_input, print_line);
	return (SUCCESS);
}
