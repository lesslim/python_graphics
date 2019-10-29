/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 21:08:00 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/12 20:59:22 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *data, size_t data_size)
{
	t_list *tmp;

	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (data == NULL)
	{
		tmp->data = NULL;
		tmp->data_size = 0;
	}
	else
	{
		if (!(tmp->data = malloc(data_size)))
			return (NULL);
		tmp->data = ft_memcpy(tmp->data, data, data_size);
		tmp->data_size = data_size;
	}
	tmp->next = NULL;
	return (tmp);
}
