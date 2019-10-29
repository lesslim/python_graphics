/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 04:34:36 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 22:33:19 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*find_room(char *line, t_room **room, int key)
{
	t_room	*r;

	r = *(room + key);
	while (r)
	{
		if (!ft_strcmp(line, r->name))
			break ;
		r = r->next;
	}
	return (r);
}

t_room	*find_room_id(t_room **room, int key, int id)
{
	t_room	*r;

	if (key < 0 || id < 0)
		return (NULL);
	r = *(room + key);
	while (id--)
	{
		if (!r)
			return (NULL);
		r = r->next;
	}
	return (r);
}

t_nbors	*find_nbors(t_nbors *nbors, int key, int id)
{
	t_nbors	*tmp;

	tmp = nbors;
	while (tmp)
	{
		if (tmp->room.k == key && tmp->room.id == id)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

void	find_and_rm_nbors(t_nbors **nbors, int key, int id)
{
	t_nbors	*tmp;
	t_nbors	*temp;

	if (*nbors && (*nbors)->room.k == key && (*nbors)->room.id == id)
	{
		tmp = (*nbors)->next;
		free(*nbors);
		*nbors = tmp;
	}
	else if (*nbors)
	{
		tmp = *nbors;
		while (tmp->next)
		{
			if (tmp->next->room.k == key && tmp->next->room.id == id)
			{
				temp = tmp->next->next;
				free(tmp->next);
				tmp->next = temp;
				return ;
			}
			tmp = tmp->next;
		}
	}
}

int		key_table(const char *line)
{
	int		key;
	size_t	size;

	size = 0;
	while (*(line + size) && !ft_isspace(*(line + size)) && size < 4)
		size++;
	key = 0;
	key += *line - 33;
	if (size > 1)
		key += (*(line + 1) - 33) * NINEFOUR_ONE;
	if (size > 2)
		key += (*(line + 2) - 33) * NINEFOUR_TWO;
	if (size > 3)
		key += (*(line + 3) - 33) * NINEFOUR_THREE;
	key %= 7993;
	if (key < 0)
		key *= -1;
	return (key);
}
