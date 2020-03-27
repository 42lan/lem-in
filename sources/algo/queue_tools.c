/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 21:20:01 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/27 21:20:55 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include "libft.h"

int		queue_isfull(t_queue *queue)
{
	if (queue->size == queue->capacity)
		return (SUCCESS);
	return (FAILURE);
}

int		queue_isempty(t_queue *queue)
{
	if (queue->size == 0)
		return (SUCCESS);
	return (FAILURE);
}

void	queue_print(t_queue *queue)
{
	int	i;

	i = -1;
	while (++i < queue->size)
		ft_printf("[%d]", queue->array[i]);
	ft_printf("\n");
}
