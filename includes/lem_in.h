/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:17:01 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 22:45:44 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

# include <time.h>
# include <stdio.h>

# define COM_START "##start"
# define COM_END "##end"

enum	e_steps {FALSE, ROOM, START, END, EDGE, IGNOR};

# define NINEFOUR_ONE 94
# define NINEFOUR_TWO 8836
# define NINEFOUR_THREE 830584

# define SIZE_OF_TABLE 7993

typedef struct		s_id
{
	int				k;
	int				id;
}					t_id;

typedef struct		s_nbors
{
	t_id			room;
	struct s_nbors	*next;
}					t_nbors;

typedef struct		s_room
{
	int				id;
	char			*name;
	t_id			from;
	int				level;
	size_t			path : 1;
	size_t			path0 : 1;
	t_nbors			*nbors;
	struct s_room	*next;
}					t_room;

typedef struct		s_init_cond
{
	int				ants;
	int				fd;
	char			flag;
	t_id			start;
	t_id			end;
}					t_init_cond;

typedef struct		s_ant
{
	int				n;
	t_room			*room;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_path
{
	t_id			room;
	int				ants;
	int				len;
	struct s_path	*next;
}					t_path;

void				parse(t_init_cond **cond, t_room ***room);
void				edge(char *line, t_room ***room, int code, int fd);
void				add_room(char *line, t_init_cond **cond, t_room ***room, \
																	int code);
int					who_is_it(const char *line);

int					bfs(t_init_cond *cond, t_room **room);
int					clever_if(t_room **rooms, t_room *room_b);
int					dfs(t_init_cond *cond, t_room **room);

t_nbors				*ft_nbors_new(int key, int id, int fd);
void				ft_add_nbors_to_room(t_room **room, t_nbors *nbors);
void				ft_add_nbors(t_nbors **nbors, t_nbors *new);
void				ft_add_last_nbors(t_nbors **nbors, t_nbors *new);
void				ft_rm_first_nbors(t_nbors **nbors);

int					key_table(const char *line);

t_room				*find_room(char *line, t_room **room, int key);
t_room				*find_room_id(t_room **room, int key, int id);
t_nbors				*find_nbors(t_nbors *nbors, int key, int id);
void				find_and_rm_nbors(t_nbors **nbors, int key, int id);

void				set_from(t_room **rooms, int from);
void				set_path(t_room **rooms);
void				set_level(t_room **rooms, int level);

int					ft_step(t_init_cond *cond, t_room **rooms);
void				fix_paths(t_init_cond *cond, t_room **rooms);
void				delete_unused(t_init_cond *cond, t_room **rooms);

void				route(t_init_cond *cond, t_room **room, int step);
void				length(t_init_cond *cond, t_room **rooms, int len);
t_path				*path_is_free(t_room **rooms, t_ant *ant, t_path *path);

void				ft_add_path(t_path **path, t_path *new);
t_path				*ft_path_new(int len, t_id room, int ants, int fd);
void				ft_free_path(t_path **path);

void				ft_add_ant(t_ant **ant, t_ant *new);
t_ant				*ft_ant_new(int number, t_room **room, int fd);
void				ft_rm_ant(t_ant **ant, t_room *room);

void				init_tables(t_init_cond **cond, t_room ***room);
void				init_ant_and_path(t_init_cond *cond, t_room **rooms, \
												t_ant **ant, t_path **path);

void				freedom(t_init_cond **cond, t_room ***rooms);

int					ft_exit(int fd, char *str, int n);

#endif
