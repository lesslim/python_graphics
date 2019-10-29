/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:13:55 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/02 16:12:28 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfold(t_list *lst, void *(f)(void *el1, void *el2))
{
	void	*tmp;

	if (!lst)
		return (NULL);
	if (lst && !lst->next)
		return (lst->data);
	if (lst && lst->next)
		tmp = f(lst->data, lst->next->data);
	if (!!(lst = lst->next->next))
		while (lst)
		{
			tmp = f(tmp, lst->data);
			lst = lst->next;
		}
	return (tmp);
}
