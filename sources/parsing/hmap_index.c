/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmap_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 16:12:48 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/21 17:25:18 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

#include "lemin.h"

int			hmap_index(char *key)
{
	int		i;
	int		hash;

	i = -1;
	hash = 0;
	while (key[++i])
		hash += key[i];
	return (hash % HMAP_SIZE);
}
