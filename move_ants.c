/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_ants.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/26 16:36:26 by rcorke         #+#    #+#                */
/*   Updated: 2019/09/23 10:56:35 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			make_ant_struct(t_table *lem)
{
	int x;
	int	shortest_index;

	x = 0;
	while (x < lem->ants)
	{
		lem->ant_table[x] = (t_ants *)malloc(sizeof(t_ants));
		lem->ant_table[x]->index = -1;
		shortest_index = return_shortest_path_index(lem);
		lem->ant_table[x]->path_index = shortest_index;
		lem->rp[shortest_index]->temp_size += 1;
		lem->ant_table[x]->done = 0;
		x++;
	}
}

static void		move_ant(t_table *lem, int ant, char *o_table)
{
	if (lem->ant_table[ant]->index == \
	lem->rp[lem->ant_table[ant]->path_index]->size - 1)
	{
		lem->ant_table[ant]->done = 1;
		return ;
	}
	if (lem->ant_table[ant]->index == -1 && \
	o_table[lem->ant_table[ant]->path_index] == 1)
		return ;
	if (lem->ant_table[ant]->index == -1 && \
	o_table[lem->ant_table[ant]->path_index] == 0)
	{
		o_table[lem->ant_table[ant]->path_index] = 1;
		lem->ant_table[ant]->index = 0;
	}
	else if (o_table[lem->ant_table[ant]->path_index] == 1 && \
	lem->ant_table[ant]->index == 0)
	{
		lem->ant_table[ant]->index += 1;
		o_table[lem->ant_table[ant]->path_index] = 0;
	}
	else if (lem->ant_table[ant]->index > 0)
		lem->ant_table[ant]->index += 1;
	return (print_movement(ant, \
	lem->rp[lem->ant_table[ant]->path_index]->str[lem->ant_table[ant]->index]));
}

int				ants_done(t_table *lem)
{
	int x;

	x = 0;
	while (x < lem->ants)
	{
		if (lem->ant_table[x]->done == 0)
			return (1);
		x++;
	}
	return (0);
}

static char		*fill_occupied_table(t_table *lem)
{
	char	*o_table;
	int		i;

	o_table = ft_strnew(lem->num_real_paths);
	i = 0;
	while (i < lem->num_real_paths)
	{
		o_table[i] = 0;
		i++;
	}
	return (o_table);
}

void			move_ants(t_table *lem)
{
	int		x;
	char	*occupied_table;

	occupied_table = fill_occupied_table(lem);
	lem->ant_table = (t_ants **)malloc(sizeof(t_ants *) * lem->ants);
	make_ant_struct(lem);
	x = 0;
	while (ants_done(lem))
	{
		if (x == lem->ants)
		{
			x = 0;
			ft_printf("\n");
		}
		if (lem->ant_table[x]->done == 0)
		{
			move_ant(lem, x, occupied_table);
		}
		x++;
	}
	free(occupied_table);
}
