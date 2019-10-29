/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 04:33:01 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 01:29:36 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant	*ft_ant_new(int number, t_room **room, int fd)
{
	t_ant	*ant;

	if (!(ant = (t_ant *)malloc(sizeof(t_ant))))
		ft_exit(fd, NULL, -2);
	ant->room = (room && *room ? *room : NULL);
	ant->n = number;
	ant->next = NULL;
	return (ant);
}

void	ft_add_ant(t_ant **ant, t_ant *new)
{
	t_ant	*tmp;

	if (new)
	{
		if (!(*ant))
			*ant = new;
		else
		{
			tmp = *ant;
			*ant = new;
			new->next = tmp;
		}
	}
}

void	ft_rm_ant(t_ant **ant, t_room *room)
{
	t_ant	*tmp;
	t_ant	*temp;

	if (ant && *ant)
	{
		if ((*ant)->room && (*ant)->room == room)
		{
			tmp = (*ant)->next;
			free(*ant);
			*ant = tmp;
		}
		else if ((*ant)->next)
		{
			tmp = *ant;
			while (tmp->next && tmp->next->room != room)
				tmp = tmp->next;
			if (tmp->next)
			{
				temp = tmp->next;
				tmp->next = tmp->next->next;
				free(temp);
			}
		}
	}
}
