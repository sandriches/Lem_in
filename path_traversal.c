/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_traversal.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 14:01:14 by rcorke         #+#    #+#                */
/*   Updated: 2019/09/23 10:58:06 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		make_flow_paths(t_table *lem, int flow)
{
	int i;

	i = 0;
	lem->temp_paths = (t_path **)malloc(sizeof(t_path *) * flow);
	while (i < flow)
	{
		lem->temp_paths[i] = (t_path *)malloc(sizeof(t_path));
		lem->temp_paths[i]->node = lem->link_table[lem->start_index];
		lem->temp_paths[i]->next = NULL;
		lem->temp_paths[i]->size = 0;
		make_path(lem, lem->temp_paths[i]);
		new_bfs(lem, 3);
		i++;
	}
}

int				get_path_size(t_path *path)
{
	t_path *iter;

	iter = path;
	while (iter->next)
		iter = iter->next;
	return (iter->size);
}

void			path_traversal(t_table *lem)
{
	int		flow;

	flow = 0;
	while (new_bfs(lem, 1) && flow < lem->ants)
	{
		flow++;
		remove_dead_links(lem);
	}
	if (flow == 0)
		no_connection_error(lem);
	new_bfs(lem, 2);
	make_flow_paths(lem, flow);
	lem->num_of_paths = flow;
}
