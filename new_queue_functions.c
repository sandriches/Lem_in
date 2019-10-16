/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_queue_functions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 12:14:51 by rcorke         #+#    #+#                */
/*   Updated: 2019/09/23 10:55:55 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		dequeue(t_q *queue)
{
	queue->index++;
}

t_links		*get_front(t_q *queue)
{
	return (queue->nodes[queue->index]);
}

void		enqueue(t_q *queue, int distance, t_links *node)
{
	if (!node)
		return ;
	queue->nodes[queue->size] = node;
	queue->size++;
	node->distance = distance + 1;
	node->bfs_visited = 1;
}

void		free_queue(t_q *q)
{
	free(q->nodes);
	free(q);
}

t_q			*create_queue(t_table *lem)
{
	t_q *queue;

	queue = (t_q *)malloc(sizeof(t_q));
	queue->nodes = (t_links **)malloc(sizeof(t_links *) * lem->rooms);
	queue->size = 0;
	queue->index = 0;
	return (queue);
}
