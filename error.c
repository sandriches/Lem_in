/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/10 13:10:59 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/09/28 16:28:27 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	multiple_start_end_error(t_table *lem)
{
	free_everything(lem);
	write(2, "Error - multiple start/end rooms\n", 33);
	exit(0);
}

void	no_connection_error(t_table *lem)
{
	free_everything(lem);
	write(2, "Error - no links from start -> end\n", 35);
	exit(0);
}

void	no_start_end_error(t_table *lem)
{
	free_everything(lem);
	write(2, "Error - incorrect/no start/end\n", 31);
	exit(0);
}

void	room_not_found_error(t_table *lem)
{
	free_everything(lem);
	write(2, "Error - room not found\n", 23);
	exit(0);
}

void	wrong_input_error(t_table *lem, char *line)
{
	free_everything(lem);
	if (line)
		free(line);
	write(2, "Error\n", 6);
	exit(0);
}
