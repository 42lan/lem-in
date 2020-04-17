/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <abosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:17:30 by abosch            #+#    #+#             */
/*   Updated: 2020/04/17 20:41:54 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "del.h"
#include "lemin.h"
#include <stdlib.h>

void	del_link_list(void *no, size_t u)
{
	(void)no;
	(void)u;
}

void	del_link(void *link, size_t useless)
{
	(void)useless;
	free(((t_link*)link)->arr);
	ft_list_del(&(((t_link*)link)->list), &del_link_list);
}

void	del_room(void *room)
{
	ft_strdel(&(((t_room*)room)->name));
	del_link(&(((t_room*)room)->link.list), 0);
}

void	final_free(void)
{
	int	i;

	i = -1;
	while ((unsigned)++i < g_farm.size)
		del_room(&ROOMS[i]);
	free(ROOMS);
}
