/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 20:39:23 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/17 05:07:48 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*myft_lstnew(void const *data, size_t fd)
{
	t_list *tmp;

	if (!(tmp = malloc(sizeof(t_list))))
		return (NULL);
	tmp->data_size = fd;
	if (data == NULL)
		tmp->data = NULL;
	else
	{
		if (!(tmp->data = malloc(ft_strlen(data) + 1)))
		{
			free(tmp);
			return (NULL);
		}
		tmp->data = ft_memcpy(tmp->data, data, ft_strlen(data) + 1);
	}
	tmp->next = NULL;
	return (tmp);
}

static t_list		*myft_lstfind(t_list *lst, int fd)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	if (lst->data_size == (size_t)fd)
		return (lst);
	tmp = lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->data_size == (size_t)fd)
			return (tmp);
	}
	return (NULL);
}

static void			deep_back_gnl(char **line, t_list *lst)
{
	int				i;

	i = 0;
	while (*(char *)(lst->data + i) != '\n' && \
				*(char *)(lst->data + i) != '\0')
		i++;
	*line = ft_strnew(i);
	while (--i + 1 != 0)
		*(*line + i) = *(char *)(lst->data + i);
}

static ssize_t		back_gnl(const size_t fd, ssize_t state, void **str)
{
	char	*buff;
	char	*buffer;

	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	if ((state = read(fd, buff, BUFF_SIZE)) < 0)
	{
		free(buff);
		return (-1);
	}
	if (*str)
		buffer = ft_strdup(*str);
	else
		buffer = ft_strnew(1);
	if (*str)
		free(*str);
	*str = ft_strjoin(buffer, buff);
	free(buffer);
	free(buff);
	return (state);
}

int					get_next_line(const int fd, char **line)
{
	char			*buffer;
	ssize_t			state;
	t_list			*lst;
	static t_list	*head = NULL;

	while ((lst = myft_lstfind(head, fd)) == NULL)
		ft_lstadd(&head, myft_lstnew(NULL, (size_t)fd));
	state = BUFF_SIZE;
	while (ft_strchr((char *)lst->data, '\n') == NULL && state > 0)
		state = back_gnl(lst->data_size, state, &lst->data);
	if (state < 0)
		return (-1);
	deep_back_gnl(line, lst);
	buffer = ft_strsub(lst->data, ft_strlen(*line) + 1,\
ft_strlen(lst->data) - ft_strlen(*line));
	if (lst->data)
		free(lst->data);
	lst->data = ft_strdup(buffer);
	free(buffer);
	if (state == 0 && **line == '\0')
		return (state);
	return (1);
}
