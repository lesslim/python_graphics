/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:45:22 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/02 21:21:27 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, void *trg)
{
	t_list	*tmp;

	if (!lst || !trg)
		return (NULL);
	if (!ft_strcmp(trg, lst->data))
		return (lst);
	tmp = lst->next;
	while (tmp)
	{
		if (!ft_strcmp(trg, tmp->data))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
