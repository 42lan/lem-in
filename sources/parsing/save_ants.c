/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:49:08 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/17 17:49:14 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

unsigned int	save_ants(t_list *uncommented_input)
{
	int			number_of_ants;

	number_of_ants = ft_atoi(uncommented_input->head->content);
	return (number_of_ants);
}
