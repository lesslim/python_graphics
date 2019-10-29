/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:10:20 by nhamill           #+#    #+#             */
/*   Updated: 2019/09/25 10:06:05 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *str)
{
	int		i;
	size_t	len;
	char	*rev;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (!(rev = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (i++ != (int)len)
		rev[i] = str[len - i - 1];
	rev[len] = '\0';
	return (rev);
}
