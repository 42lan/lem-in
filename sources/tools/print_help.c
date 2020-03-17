/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:20:48 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/13 22:21:11 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_help(void)
{
	ft_printf("Lem-in - ant farm manager\n");
	ft_printf("\tusage: ./lem-in [options] < map\n");
	exit(SUCCESS);
}
