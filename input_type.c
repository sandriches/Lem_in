/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_type.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/27 14:55:01 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/09/20 16:38:38 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	only_numbers(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		if (!ft_isdigit(str[x]))
			return (0);
		x++;
	}
	if (ft_atoi(str) == 0)
		return (0);
	if (ft_fits_in_int(str))
		return (1);
	return (0);
}

static int	is_room(char *str)
{
	int x;

	x = 0;
	if (str[0] == 'L')
		return (0);
	while (str[x] && str[x] != ' ')
		x++;
	if (!str[x] || !str[x + 1] || !ft_isdigit(str[x + 1]))
		return (0);
	x++;
	while (str[x] && ft_isdigit(str[x]))
		x++;
	if (!str[x] || str[x] != ' ' || !str[x + 1] || !ft_isdigit(str[x + 1]))
		return (0);
	x++;
	while (ft_isdigit(str[x]))
		x++;
	if (str[x])
		return (0);
	return (1);
}

static int	check_around_dashes(char *str)
{
	int x;

	x = 0;
	while (str[x] && str[x] != '-')
	{
		if (str[x] == ' ' || str[x] == '\t')
			return (0);
		x++;
	}
	while (str[x])
	{
		if (str[x] == ' ' || str[x] == '\t')
			return (0);
		x++;
	}
	return (1);
}

static int	is_link(char *str, int len)
{
	int	x;
	int	dashes;

	if (!str || !ft_strchr(str, '-') || str[0] == '-' || \
	str[len - 1] == '-')
		return (0);
	x = 0;
	dashes = 0;
	while (str[x] != '\0')
	{
		if (str[x] == '-')
			dashes++;
		x++;
	}
	if (dashes != 1)
		return (0);
	return (check_around_dashes(str));
}

int			input_type(char *str)
{
	int len;

	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (str && len > 0 && str[0] == '#')
		return (4);
	else if (only_numbers(str))
		return (1);
	else if (is_room(str))
		return (2);
	else if (is_link(str, len))
		return (3);
	return (-1);
}
