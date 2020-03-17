/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 22:16:49 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/16 22:33:51 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		initialize_data(t_data *data)
{
	data->raw_input = NULL;
}

static void		initialize_farm(t_farm *farm)
{
	farm->number_of_ants = -1;
	farm->rooms = NULL;
	farm->links = NULL;
}

void	initialization(t_data *data)
{
	initialize_data(data);
	initialize_farm(data->farm);
}
