/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:54:23 by nhamill           #+#    #+#             */
/*   Updated: 2018/12/13 19:03:26 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*s;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(s = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	ft_bzero(s, len);
	ft_strlcat(s, (char *)s1, len);
	ft_strlcat(s, (char *)s2, len);
	return (s);
}
