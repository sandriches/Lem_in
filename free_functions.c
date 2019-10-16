/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/20 12:44:56 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/09/20 12:45:30 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_hash_table(t_table *lem)
{
	int		x;
	t_hash	*iter;
	t_hash	*to_free;

	x = 0;
	while (x < lem->rooms)
	{
		if (lem->hash_table[x])
		{
			iter = lem->hash_table[x];
			while (iter)
			{
				to_free = iter;
				iter = iter->next;
				free(to_free->name);
				free(to_free);
				to_free = NULL;
			}
		}
		x++;
	}
	free(lem->hash_table);
	lem->hash_table = NULL;
}

void	free_link_table(t_table *lem)
{
	int		x;
	t_links	*iter;
	t_links	*to_free;

	x = 0;
	while (x < lem->rooms)
	{
		if (lem->link_table[x])
		{
			iter = lem->link_table[x];
			while (iter)
			{
				to_free = iter;
				iter = iter->next;
				free(to_free->str);
				free(to_free);
				to_free = NULL;
			}
		}
		x++;
	}
	free(lem->link_table);
	lem->link_table = NULL;
}

void	free_rp(t_table *lem)
{
	int x;

	x = 0;
	while (x < lem->num_real_paths)
	{
		if (lem->rp[x]->str)
			free(lem->rp[x]->str);
		if (lem->rp[x])
			free(lem->rp[x]);
		lem->rp[x] = NULL;
		x++;
	}
	free(lem->rp);
	lem->rp = NULL;
}

void	free_storage(t_table *lem)
{
	t_store *iter;
	t_store	*to_free;

	iter = lem->storage;
	while (iter->next)
	{
		to_free = iter;
		iter = iter->next;
		if (to_free)
		{
			if (to_free->str)
				free(to_free->str);
			free(to_free);
		}
		to_free = NULL;
	}
	if (iter)
	{
		if (iter->str)
			free(iter->str);
		free(iter);
	}
	iter = NULL;
}
