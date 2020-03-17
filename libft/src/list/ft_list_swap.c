/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:33:53 by abaisago          #+#    #+#             */
/*   Updated: 2020/03/01 14:40:35 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_swap(t_list_link *a, t_list_link *b)
{
	t_list_link	tmp;

	if (a->next == a || b->next == b)
		return ;
	a->prev->next = b;
	a->next->prev = b;
	b->prev->next = a;
	b->next->prev = a;
	tmp.prev = a->prev;
	tmp.next = a->next;
	a->prev = b->prev;
	a->next = b->next;
	b->prev = tmp.prev;
	b->next = tmp.next;
}
