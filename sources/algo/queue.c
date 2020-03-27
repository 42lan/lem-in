/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 12:30:52 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/27 12:55:43 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "queue.h"

t_queue			*queue_create(unsigned capacity)
{
	t_queue		*queue;

	if (!(queue = (t_queue *)ft_memalloc(sizeof(t_queue))))
		return (NULL);
	queue->front = 0;
	queue->rear = capacity - 1;
	queue->size = 0;
	queue->capacity = capacity;
	if (!(queue->array = (int *)ft_memalloc(sizeof(int) * capacity)))
		return (NULL); 
	return (queue);
}

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
