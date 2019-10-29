/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 21:41:33 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/02 16:11:26 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while (alst && *alst)
	{
		del((*alst)->data, (*alst)->data_size);
		free(*alst);
		*alst = (*alst)->next;
	}
	*alst = NULL;
}
