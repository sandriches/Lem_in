/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_traversal_2.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/20 12:55:00 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/09/20 12:56:06 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_links	*get_next_node(t_table *lem, t_links *node)
{
	t_links *iter;
	t_links	*bestest;

	bestest = NULL;
	iter = node->next;
	while (iter)
	{
		if ((!bestest || lem->link_table[iter->index]->distance < \
		bestest->distance) && lem->link_table[iter->index]->distance != -1 && \
		iter->out == 0 && lem->link_table[iter->index]->trav_visited == 0)
			bestest = lem->link_table[iter->index];
		iter = iter->next;
	}
	return (bestest);
}

void	set_in_out(t_links *node, t_links *next_node)
{
	t_links *iter;

	iter = node->next;
	while (ft_strcmp(next_node->str, iter->str))
		iter = iter->next;
	iter->out = 1;
	iter = next_node->next;
	while (ft_strcmp(node->str, iter->str))
		iter = iter->next;
	iter->in = 1;
}

void	remove_dead_links(t_table *lem)
{
	t_links *node;
	t_links	*next_node;

	node = lem->link_table[lem->start_index];
	while (node->distance > 0)
	{
		next_node = get_next_node(lem, node);
		set_in_out(node, next_node);
		next_node->trav_visited = 1;
		node = next_node;
	}
}

t_links	*get_lowest_distance(t_table *lem, t_links *node)
{
	t_links *iter;
	t_links	*best;

	best = NULL;
	iter = node->next;
	while (iter)
	{
		if ((!best || lem->link_table[iter->index]->distance < best->distance) \
		&& lem->link_table[iter->index]->bfs_visited != 2 && \
		lem->link_table[iter->index]->distance != -1 && (iter->in == 0 || \
		iter->out == 0))
			best = lem->link_table[iter->index];
		iter = iter->next;
	}
	return (best);
}

void	make_path(t_table *lem, t_path *path)
{
	t_links *lowest;

	while (path->node->distance > 0)
	{
		lowest = get_lowest_distance(lem, path->node);
		lowest->bfs_visited = 2;
		path->next = (t_path *)malloc(sizeof(t_path));
		path->next->node = lowest;
		path->next->size = path->size + 1;
		path->next->next = NULL;
		path = path->next;
	}
	lem->link_table[lem->end_index]->bfs_visited = 0;
}
