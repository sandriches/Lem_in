/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/09 17:08:34 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/09/20 12:50:22 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	set_all_to_null(t_table *lem)
{
	lem->ant_table = NULL;
	lem->start = NULL;
	lem->end = NULL;
	lem->hash_table = NULL;
	lem->link_table = NULL;
	lem->paths = NULL;
	lem->rp = NULL;
	lem->storage = NULL;
	lem->ants = 0;
}

int			main(void)
{
	t_table	*lem;

	lem = (t_table *)malloc(sizeof(t_table));
	set_all_to_null(lem);
	store_input(lem);
	make_tables(lem);
	lem->start_index = link_index(lem, lem->start);
	lem->end_index = link_index(lem, lem->end);
	path_traversal(lem);
	make_real_paths(lem);
	print_storage(lem);
	move_ants(lem);
	free_everything(lem);
	return (0);
}
