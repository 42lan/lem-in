/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 22:16:49 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/17 19:40:29 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		initialize_data(t_data *data)
{
	data->raw_input = NULL;
}

void	initialization(t_data *data)
{
	initialize_data(data);
}
