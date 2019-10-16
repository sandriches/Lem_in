/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_real_paths.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 12:38:34 by rcorke         #+#    #+#                */
/*   Updated: 2019/09/23 10:56:58 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			del_real_paths(t_path **path, int num_nodes)
{
	int		x;
	t_path	*iter;

	x = 0;
	while (x < num_nodes)
	{
		iter = path[x];
		while (iter)
		{
			path[x] = iter;
			free(path[x]);
			path[x] = NULL;
			iter = iter->next;
		}
		x++;
	}
	free(path);
	path = NULL;
}

char			**link_list_to_array(t_table *lem, t_path *path, int size)
{
	t_path	*iter;
	char	**arr;
	int		x;

	x = 0;
	arr = (char **)malloc(sizeof(char *) * size + 1);
	iter = path->next;
	while (x < size - 1)
	{
		arr[x] = iter->node->str;
		iter = iter->next;
		x++;
	}
	arr[x] = lem->link_table[lem->end_index]->str;
	arr[x + 1] = NULL;
	return (arr);
}

t_rp			**convert_paths(t_table *lem)
{
	t_rp		**real_paths;
	int			i;
	t_path		*iter;

	real_paths = (t_rp **)malloc(sizeof(t_rp *) * lem->num_real_paths + 1);
	i = 0;
	while (i < lem->num_real_paths)
	{
		real_paths[i] = (t_rp *)malloc(sizeof(t_rp));
		iter = lem->paths[i];
		while (iter->next)
			iter = iter->next;
		real_paths[i]->size = iter->size;
		real_paths[i]->temp_size = real_paths[i]->size;
		real_paths[i]->str = link_list_to_array(lem, lem->paths[i], iter->size);
		i++;
	}
	del_real_paths(lem->paths, lem->num_real_paths);
	real_paths[i] = NULL;
	return (real_paths);
}

static void		clear_empty_paths(t_table *lem)
{
	int		x;

	x = 0;
	while (x < lem->num_of_paths)
	{
		if (get_path_size(lem->paths[x]) == 0)
		{
			free(lem->paths[x]);
			lem->paths[x] = NULL;
			lem->num_real_paths -= 1;
		}
		x++;
	}
}

void			make_real_paths(t_table *lem)
{
	lem->paths = lem->temp_paths;
	lem->num_real_paths = lem->num_of_paths;
	clear_empty_paths(lem);
	lem->rp = convert_paths(lem);
}
