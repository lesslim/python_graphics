/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 04:40:28 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 00:02:37 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	it_is_room(const char *line)
{
	size_t	i;

	i = 0;
	while (*(line + i) != ' ' && *(line + i))
		i++;
	if (*(line + i) && *(line + i) == ' ')
		i++;
	else
		return (0);
	if (ft_isdigit(*(line + i)))
		while (ft_isdigit(*(line + i)))
			i++;
	else
		return (0);
	if (*(line + i) && *(line + i) == ' ')
		i++;
	else
		return (0);
	if (ft_isdigit(*(line + i)))
		while (ft_isdigit(*(line + i)))
			i++;
	else
		return (0);
	return (*(line + i) ? 0 : 1);
}

static int	it_is_edge(const char *line)
{
	size_t	i;

	i = 0;
	if (*(line + i) == '-')
		i++;
	while (*(line + i) && *(line + i) != '-' && !ft_isspace(*(line + i)))
		i++;
	if (*(line + i) != '-' || (*(line + i) && !(*(line + i + 1))))
		return (0);
	while (*(line + i) && !ft_isspace(*(line + i)))
		i++;
	if (!(*(line + i)))
		return (1);
	return (0);
}

int			who_is_it(const char *line)
{
	if (!line || *line == 'L')
		return (FALSE);
	if (it_is_room(line))
		return (ROOM);
	else if (!ft_strcmp(line, COM_START))
		return (START);
	else if (!ft_strcmp(line, COM_END))
		return (END);
	else if (*line == '#')
		return (IGNOR);
	else if (it_is_edge(line))
		return (EDGE);
	return (FALSE);
}
