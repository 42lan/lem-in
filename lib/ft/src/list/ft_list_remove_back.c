/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:12:23 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/30 13:42:21 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_remove_back(t_list *list, void (*del)(void *, size_t))
{
	if (list->len == 0)
		return ;
	ft_list_remove(list, list->head->prev, del);
}
