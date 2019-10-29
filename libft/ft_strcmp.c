/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:30:47 by nhamill           #+#    #+#             */
/*   Updated: 2018/12/16 19:17:47 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				num;
	unsigned char	c1;
	unsigned char	c2;

	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && *s1++ && *s2++)
		;
	c1 = *s1;
	c2 = *s2;
	num = c1 - c2;
	return (num);
}