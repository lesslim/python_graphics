/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 22:12:38 by nhamill           #+#    #+#             */
/*   Updated: 2018/12/13 17:05:33 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if ((s1 != NULL) && (s2 != NULL) && (ft_strcmp(s1, s2) == 0))
		return (1);
	return (0);
}
