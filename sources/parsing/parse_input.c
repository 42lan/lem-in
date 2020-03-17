/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 09:32:10 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/17 17:49:28 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			print_line(void *content, size_t size, unsigned pos)
{
	(void)pos;
	return (ft_printf("[%s] %d\n", (char *)content, size));
}

int			parse_input(t_data *data)
{
	data->raw_input = save_raw_input();
	data->uncommented_input = uncomment_raw_input(data->raw_input);
	data->number_of_ants = save_ants(data->uncommented_input);
	data->rooms = save_rooms(data->uncommented_input, data->uncommented_input->size);
	data->links = save_links(data->uncommented_input, data->uncommented_input->size);

	ft_putendl("UNCOMMENTED INPUT");
	if (data->uncommented_input != NULL)
		ft_list_print(data->uncommented_input, print_line);
	ft_putendl("");
	ft_putendl("ROOMS");
	if (data->rooms != NULL)
		ft_list_print(data->rooms, print_line);
	ft_putendl("");
	ft_putendl("LIKS");
	if (data->links != NULL)
		ft_list_print(data->links, print_line);
	//if (data->raw_input != NULL)
	//	ft_list_print(data->raw_input, print_line);
	return (SUCCESS);
}
