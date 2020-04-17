/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:17:30 by abosch            #+#    #+#             */
/*   Updated: 2020/04/17 19:54:50 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "del.h"
#include "lemin.h"

void	del_link(void *no, size_t u)
{
	(void)no;
	(void)u;
}

void	final_free(void)
{
	int	i;

	i = -1;
	while ((unsigned)++i < g_farm.size)
	{
		ft_list_del(&(ROOMS[i].link.list), &del_link);
	}
}
