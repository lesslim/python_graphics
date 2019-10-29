/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 23:29:48 by nhamill           #+#    #+#             */
/*   Updated: 2019/09/28 14:03:23 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(size + 1)))
		return (NULL);
	else
		ft_bzero(tmp, size + 1);
	return (tmp);
}
