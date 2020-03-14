/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_farm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 13:51:52 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/14 22:19:00 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	initialize_farm(t_farm *farm)
{
	farm->number_of_ants = -1;
	farm->rooms = NULL;
	farm->links = NULL;
}
