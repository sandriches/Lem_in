/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hash_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/10 14:19:48 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/09/20 16:43:30 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				lemin_list_len(t_links *list)
{
	t_links *iter;
	int		x;

	iter = list;
	x = 0;
	while (iter)
	{
		x++;
		iter = iter->next;
	}
	return (x);
}

t_links			*get_link(t_table *lem, char *str)
{
	return (lem->link_table[link_index(lem, str)]);
}

int				link_index(t_table *lem, char *str)
{
	int		hash_index;
	t_hash	*iter;

	hash_index = lemin_hash(str, lem->rooms);
	iter = lem->hash_table[hash_index];
	if (!iter)
		room_not_found_error(lem);
	while (iter && !ft_strequ(str, iter->name))
		iter = iter->next;
	if (!iter)
		room_not_found_error(lem);
	return (iter->index);
}

int				lemin_hash(char *str, int rooms)
{
	int		ascii;
	int		i;

	ascii = 0;
	i = 0;
	while (str[i] != '\0')
	{
		ascii += (int)str[i];
		i++;
	}
	return (ascii % rooms);
}
