/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_bfs.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 12:07:56 by rcorke         #+#    #+#                */
/*   Updated: 2019/09/23 10:57:39 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_links	*get_backtrack_node(t_table *lem, t_links *node)
{
	t_links *iter;

	iter = node->next;
	while (iter)
	{
		if (iter->in == 0 && iter->out == 1 && \
		lem->link_table[iter->index]->trav_visited == 1 && \
		lem->link_table[iter->index]->bfs_visited == 0)
		{
			lem->link_table[iter->index]->trav_visited = 0;
			return (lem->link_table[iter->index]);
		}
		iter = iter->next;
	}
	return (NULL);
}

static void		add_links_to_queue_first(t_table *lem, t_q *q, \
t_links *node, t_links *iter)
{
	iter = node->next;
	while (iter)
	{
		if (node->trav_visited == 0 && \
		lem->link_table[iter->index]->bfs_visited == 0 && iter->in == 0)
		{
			if (lem->link_table[iter->index]->trav_visited == 1)
				lem->link_table[iter->index]->trav_visited = 2;
			enqueue(q, node->distance, lem->link_table[iter->index]);
		}
		if (node->trav_visited == 1 && \
		lem->link_table[iter->index]->bfs_visited == 0 && iter->in == 0)
			enqueue(q, node->distance, lem->link_table[iter->index]);
		if (node->trav_visited == 2 && \
		lem->link_table[iter->index]->bfs_visited == 0 && iter->in == 0)
		{
			iter = get_backtrack_node(lem, node);
			node->trav_visited = (iter) ? 0 : 1;
			enqueue(q, node->distance, iter);
			return ;
		}
		iter = iter->next;
	}
	node->trav_visited = (node->trav_visited == 1) ? 0 : node->trav_visited;
}

static void		add_links_to_queue_second(t_table *lem, t_q *q, t_links *node)
{
	t_links	*iter;

	iter = node->next;
	while (iter)
	{
		if (lem->link_table[iter->index]->bfs_visited == 0 && \
		(iter->in == 0 || iter->out == 0))
			enqueue(q, node->distance, lem->link_table[iter->index]);
		iter = iter->next;
	}
}

static int		bfs_loop(t_table *lem, t_q *q, t_links *end, int first_or_s)
{
	t_links	*front;
	t_links	*iter;
	int		ret;

	iter = NULL;
	ret = 0;
	enqueue(q, -1, end);
	while (q->index != q->size)
	{
		front = get_front(q);
		if (ft_strequ(front->str, lem->start))
			ret = 1;
		dequeue(q);
		if (first_or_s == 1)
			add_links_to_queue_first(lem, q, front, iter);
		else
			add_links_to_queue_second(lem, q, front);
	}
	free_queue(q);
	return (ret);
}

int				new_bfs(t_table *lem, int first_or_second)
{
	t_q		*q;
	t_links	*end;

	end = lem->link_table[lem->end_index];
	q = create_queue(lem);
	reset_visited(lem, first_or_second);
	return (bfs_loop(lem, q, end, first_or_second));
}
