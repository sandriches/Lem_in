/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_storage.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/20 14:05:14 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/09/20 14:06:06 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_storage(t_table *lem)
{
	t_store *iter;
	t_store	*to_free;

	iter = lem->storage;
	while (iter->next)
	{
		ft_printf("%s\n", iter->str);
		to_free = iter;
		iter = iter->next;
		free(to_free->str);
		free(to_free);
		to_free = NULL;
	}
	free(iter);
	iter = NULL;
	lem->storage = NULL;
	ft_printf("\n");
}
