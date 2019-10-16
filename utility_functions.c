/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utility_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/20 12:48:17 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/09/23 10:58:27 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*get_room_name(char *str)
{
	int		x;

	x = 0;
	while (str[x] && str[x] != ' ')
		x++;
	return (ft_strsub(str, 0, x));
}

void	print_movement(int which_ant, char *str)
{
	ft_printf("L%d-%s ", which_ant + 1, str);
}

int		return_shortest_path_index(t_table *lem)
{
	int x;
	int rtn;

	x = 0;
	rtn = 0;
	while (x < lem->num_real_paths)
	{
		if (lem->rp[x]->temp_size < lem->rp[rtn]->temp_size)
			rtn = x;
		x++;
	}
	return (rtn);
}

void	reset_visited(t_table *lem, int first_or_second)
{
	int		i;

	i = 0;
	while (i < lem->rooms)
	{
		if (first_or_second != 3)
			lem->link_table[i]->bfs_visited = 0;
		else if (first_or_second == 3)
		{
			if (lem->link_table[i]->bfs_visited != 2)
				lem->link_table[i]->bfs_visited = 0;
		}
		lem->link_table[i]->distance = -1;
		i++;
	}
	lem->link_table[lem->end_index]->trav_visited = 0;
	lem->link_table[lem->start_index]->trav_visited = 0;
}

int		can_backtrack(t_table *lem, t_links *node)
{
	t_links *iter;

	iter = node->next;
	while (iter)
	{
		if (iter->in == 0 && iter->out == 1 && \
		lem->link_table[iter->index]->trav_visited == 1 && \
		lem->link_table[iter->index]->bfs_visited == 0)
			return (1);
		iter = iter->next;
	}
	return (0);
}
