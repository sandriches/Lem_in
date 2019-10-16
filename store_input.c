/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/10 12:44:33 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/09/23 10:56:12 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		get_links(t_store *iter)
{
	char	*line;
	int		input;

	while (get_next_line(0, &line))
	{
		input = input_type(line);
		if (input == 4 || input == 3)
			iter->str = ft_strdup(line);
		free(line);
		if (input != 4 && input != 3)
			break ;
		iter->next = (t_store *)malloc(sizeof(t_store));
		iter->next->str = NULL;
		iter = iter->next;
		iter->next = NULL;
	}
}

static int		get_rooms(t_store *iter, t_table *lem)
{
	char	*line;
	int		input;
	int		rooms;

	rooms = 0;
	while (get_next_line(0, &line))
	{
		input = input_type(line);
		if (input == 4 || input == 2 || input == 3)
			iter->str = ft_strdup(line);
		if (input == 2)
			rooms++;
		else if (input == 1 || input == -1)
			wrong_input_error(lem, line);
		free(line);
		iter->next = (t_store *)malloc(sizeof(t_store));
		iter->next->str = NULL;
		iter = iter->next;
		iter->next = NULL;
		if (input == 3)
			break ;
	}
	get_links(iter);
	return (rooms);
}

static int		get_ants(t_store *iter, t_table *lem)
{
	char	*line;
	int		input;

	while (get_next_line(0, &line))
	{
		input = input_type(line);
		if (input == 1 || input == 4)
			iter->str = ft_strdup(line);
		if (input == 1)
			lem->ants = ft_atoi(iter->str);
		else
			wrong_input_error(lem, line);
		free(line);
		iter->next = (t_store *)malloc(sizeof(t_store));
		iter->next->str = NULL;
		iter = iter->next;
		iter->next = NULL;
		if (input == 1)
			break ;
	}
	if (lem->ants == 0)
		wrong_input_error(lem, NULL);
	return (get_rooms(iter, lem));
}

void			store_input(t_table *lem)
{
	t_store *iter;

	lem->storage = (t_store *)malloc(sizeof(t_store));
	iter = lem->storage;
	iter->str = NULL;
	iter->next = NULL;
	lem->rooms = get_ants(iter, lem);
	if (lem->rooms == 0)
		wrong_input_error(lem, NULL);
}
