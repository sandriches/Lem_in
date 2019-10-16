/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_tables.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/10 14:11:43 by rcorke         #+#    #+#                */
/*   Updated: 2019/09/28 16:28:29 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	check_start_end(t_store *iter, t_table *lem)
{
	if (!ft_strcmp(iter->str, "##start"))
	{
		if (lem->start)
			multiple_start_end_error(lem);
		while (iter && iter->str[0] == '#')
			iter = iter->next;
		if (!iter)
			wrong_input_error(lem, NULL);
		lem->start = get_room_name(iter->str);
	}
	else if (!ft_strcmp(iter->str, "##end"))
	{
		if (lem->end)
			multiple_start_end_error(lem);
		while (iter && iter->str[0] == '#')
			iter = iter->next;
		if (!iter)
			wrong_input_error(lem, NULL);
		lem->end = get_room_name(iter->str);
	}
}

static void	add_to_link_table(char *str, t_table *lem, int index)
{
	lem->link_table[index] = (t_links *)malloc(sizeof(t_links));
	lem->link_table[index]->index = index;
	lem->link_table[index]->str = get_room_name(str);
	lem->link_table[index]->distance = -1;
	lem->link_table[index]->bfs_visited = 0;
	lem->link_table[index]->trav_visited = 0;
	lem->link_table[index]->num_links = 0;
	lem->link_table[index]->in = -1;
	lem->link_table[index]->out = -1;
	lem->link_table[index]->next = NULL;
}

static void	add_room(t_table *lem, char *str, int index)
{
	int		hash_index;
	t_hash	*iter;
	t_hash	*new;
	char	*room_name;

	room_name = get_room_name(str);
	hash_index = lemin_hash(room_name, lem->rooms);
	new = (t_hash *)malloc(sizeof(t_hash));
	new->name = room_name;
	new->index = index;
	new->next = NULL;
	if (!lem->hash_table[hash_index])
	{
		lem->hash_table[hash_index] = new;
		lem->hash_table[hash_index]->next = NULL;
	}
	else
	{
		iter = lem->hash_table[hash_index];
		while (iter->next)
			iter = iter->next;
		iter->next = new;
		iter->next->next = NULL;
	}
	add_to_link_table(str, lem, index);
}

static void	set_hash_to_null(t_table *lem, t_hash **hash_table)
{
	int x;

	x = 0;
	while (x < lem->rooms)
	{
		hash_table[x] = NULL;
		x++;
	}
}

void		make_tables(t_table *lem)
{
	t_store *iter;
	int		input;
	int		index;

	lem->hash_table = (t_hash **)malloc(sizeof(t_hash *) * lem->rooms);
	set_hash_to_null(lem, lem->hash_table);
	lem->link_table = (t_links **)malloc(sizeof(t_links *) * lem->rooms);
	iter = lem->storage;
	index = 0;
	while (iter->next)
	{
		input = input_type(iter->str);
		if (input == 2)
		{
			add_room(lem, iter->str, index);
			index++;
		}
		else if (input == 3)
			add_link(iter->str, lem);
		else if (input == 4)
			check_start_end(iter, lem);
		iter = iter->next;
	}
	if (!lem->start || !lem->end || ft_strequ(lem->start, lem->end))
		no_start_end_error(lem);
}
