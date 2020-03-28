/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:20:48 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/28 18:13:20 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

#include <stdlib.h>

void	print_help(void)
{
	ft_printf("Lem-in - ant farm manager\n");
	ft_printf("\tusage: ./lem-in [options] < map\n");
	exit(SUCCESS);
}
