/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:21:12 by nhamill           #+#    #+#             */
/*   Updated: 2018/12/13 17:01:57 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		n;
	char	*str;

	if (s == NULL)
		return ((char *)s);
	i = 0;
	n = 0;
	while (*s == 9 || *s == 10 || *s == 32)
		s++;
	while (s[i] != '\0')
		i++;
	while ((s[i - 1] == 9 || s[i - 1] == 10 || s[i - 1] == 32) && i != 0)
		i--;
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (i--)
		str[n++] = *s++;
	str[n] = '\0';
	return (str);
}
