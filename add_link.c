/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_link.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/10 15:02:02 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/09/16 12:12:14 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	find_dash(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '-')
		i++;
	return (i);
}

static void	add_to_link_table(t_table *lem, char *link1, char *link2)
{
	int		index;
	t_links	*iter;

	index = link_index(lem, link1);
	iter = lem->link_table[index];
	while (iter->next)
		iter = iter->next;
	iter->next = (t_links *)malloc(sizeof(t_links));
	iter->next->str = link2;
	iter->next->next = NULL;
	iter->next->index = link_index(lem, link2);
	iter->next->in = 0;
	iter->next->out = 0;
	lem->link_table[index]->num_links += 1;
}

void		add_link(char *str, t_table *lem)
{
	char	*link1;
	char	*link2;
	int		dash;

	dash = find_dash(str);
	link1 = ft_strsub(str, 0, dash);
	link2 = ft_strsub(str, dash + 1, ft_strlen(str) - (dash + 1));
	add_to_link_table(lem, link1, link2);
	add_to_link_table(lem, link2, link1);
}
