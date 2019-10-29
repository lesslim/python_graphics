/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberon-s <rberon-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 08:40:30 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/29 18:31:32 by rberon-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_arg(int ac, char **av)
{
	if (ac > 3)
		return (1);
	if (ac == 3)
	{
		if (*(*(av + 1)) != '-')
			return (1);
		if (*(*(av + 1) + 1) && (*(*(av + 1) + 1) != 's'))
			return (1);
		if (*(*(av + 1) + 2))
			return (1);
	}
	return (0);
}

static void	arguments(t_init_cond **cond, int ac, char **av)
{
	if (check_arg(ac, av))
		ft_exit(-1, NULL, -6);
	if (ac == 3)
		(*cond)->flag = *(*(av + 1) + 1);
	if (((*cond)->fd = open(*(av + ac - 1), O_RDONLY)) < 0)
		ft_exit(-1, NULL, -7);
}

static void	d_b_fs(t_init_cond *cond, t_room **room, int *step)
{
	int			step_tmp;

	step_tmp = 0;
	while (bfs(cond, room) > 0)
	{
		dfs(cond, room);
		if ((step_tmp = ft_step(cond, room)) == 1)
		{
			*step = step_tmp;
			return ;
		}
		else if ((step_tmp = ft_step(cond, room)) < *step)
		{
			set_path(room);
			set_from(room, -1);
			*step = step_tmp;
		}
		else
		{
			fix_paths(cond, room);
			return ;
		}
	}
}

int			main(int ac, char **av)
{
	t_init_cond	*cond;
	t_room		**room;
	int			step;

	init_tables(&cond, &room);
	if (ac > 1)
		arguments(&cond, ac, av);
	parse(&cond, &room);
	step = INT_MAX;
	d_b_fs(cond, room, &step);
	if (step == INT_MAX)
		ft_exit(cond->fd, NULL, -5);
	delete_unused(cond, room);
	light_printf("\n");
	route(cond, room, step);
	if (cond->flag == 's')
		light_printf("\nCount of steps: %d\n", step);
	if (cond->fd)
		if (close(cond->fd))
			ft_exit(-1, NULL, -8);
	freedom(&cond, &room);
	return (0);
}
