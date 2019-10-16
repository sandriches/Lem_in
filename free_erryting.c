/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_erryting.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 14:41:52 by rcorke         #+#    #+#                */
/*   Updated: 2019/09/20 12:45:53 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	free_ant_table(t_table *lem)
{
	int x;

	x = 0;
	while (x < lem->ants)
	{
		free(lem->ant_table[x]);
		lem->ant_table[x] = NULL;
		x++;
	}
	free(lem->ant_table);
	lem->ant_table = NULL;
}

void		free_everything(t_table *lem)
{
	if (!lem)
		return ;
	if (lem->ant_table)
		free_ant_table(lem);
	if (lem->hash_table)
		free_hash_table(lem);
	if (lem->link_table)
		free_link_table(lem);
	if (lem->rp)
		free_rp(lem);
	if (lem->storage)
		free_storage(lem);
	if (lem->start)
		free(lem->start);
	if (lem->end)
		free(lem->end);
	lem = NULL;
}
