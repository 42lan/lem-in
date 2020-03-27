/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 12:30:52 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/27 14:56:54 by amalsago         ###   ########.fr       */
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

void	queue_enqueue(t_queue *queue, int item)
{
	if (queue_isfull(queue) == SUCCESS)
		return ;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size += 1;
	queue_print(queue);
}

int		queue_dequeue(t_queue *queue)
{
	int	item;

	if (queue_isempty(queue) == SUCCESS)
		return (FAILURE);
	item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size -= 1;
	return (item);
}

void	queue_print(t_queue *queue)
{
	int	i;

	i = -1;
	while (++i < queue->capacity)
		ft_printf("[%d]", queue->array[i]);
	ft_printf("\n");
}
