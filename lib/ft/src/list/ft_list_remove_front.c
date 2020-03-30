/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:10:22 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/30 13:42:46 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_remove_front(t_list *list, void (*del)(void *, size_t))
{
	if (list->len == 0)
		return ;
	ft_list_remove(list, list->head, del);
}
