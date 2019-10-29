/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:05:38 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 01:31:32 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_nbors	*ft_nbors_new(int key, int id, int fd)
{
	t_nbors	*nbors;

	if (!(nbors = (t_nbors *)malloc(sizeof(t_nbors))))
		ft_exit(fd, NULL, -2);
	nbors->room.k = key;
	nbors->room.id = id;
	nbors->next = NULL;
	return (nbors);
}

void	ft_add_nbors_to_room(t_room **room, t_nbors *nbors)
{
	t_nbors	*tmp;

	if (!(*room)->nbors)
		(*room)->nbors = nbors;
	else
	{
		tmp = (*room)->nbors;
		(*room)->nbors = nbors;
		(*room)->nbors->next = tmp;
	}
}

void	ft_add_nbors(t_nbors **nbors, t_nbors *new)
{
	t_nbors	*tmp;

	if (new)
	{
		if (!(*nbors))
			*nbors = new;
		else
		{
			tmp = *nbors;
			*nbors = new;
			new->next = tmp;
		}
	}
}

void	ft_add_last_nbors(t_nbors **nbors, t_nbors *new)
{
	t_nbors	*tmp;

	if (new)
	{
		if (!(*nbors))
			*nbors = new;
		else
		{
			tmp = *nbors;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

void	ft_rm_first_nbors(t_nbors **nbors)
{
	t_nbors	*tmp;

	if (nbors && *nbors)
	{
		tmp = (*nbors)->next;
		free(*nbors);
		*nbors = tmp;
	}
}
