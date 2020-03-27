/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 12:30:52 by amalsago          #+#    #+#             */
/*   Updated: 2020/03/27 21:51:13 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "queue.h"

t_queue		*queue_create(unsigned capacity)
{
	t_queue	*queue;

	if (!(queue = (t_queue *)ft_memalloc(sizeof(t_queue))))
		return (NULL);
	queue->front = 0;
	queue->rear = capacity - 1;
	queue->size = 0;
	queue->capacity = capacity;
	if (!(queue->array = (int *)ft_memalloc(sizeof(int) * capacity)))
	{
		ft_memdel((void **)&queue);
		return (NULL); 
	}
	return (queue);
}

void		queue_destroy(t_queue *queue)
{
	queue->front = 0;
	queue->rear = 0;
	queue->size = 0;
	queue->capacity = 0;
	ft_memdel((void **)&queue->array);
	ft_memdel((void **)&queue);
}

void		queue_enqueue(t_queue *queue, int item)
{
	if (queue_isfull(queue) == SUCCESS)
		return ;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size += 1;
	queue_print(queue);
}

int			queue_dequeue(t_queue *queue)
{
	int	item;

	if (queue_isempty(queue) == SUCCESS)
		return (FAILURE);
	item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size -= 1;
	return (item);
}
