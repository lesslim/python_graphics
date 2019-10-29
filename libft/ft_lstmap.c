/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 21:43:11 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/02 16:11:50 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*head;

	if (lst && f)
	{
		tmp = ft_lstnew(f(lst)->data, f(lst)->data_size);
		head = tmp;
		lst = lst->next;
		while (lst)
		{
			tmp->next = ft_lstnew(f(lst)->data, f(lst)->data_size);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	else
		return (NULL);
	return (head);
}
