/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:28:40 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 22:20:33 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_string(char *str, size_t *i, size_t *j, char *s)
{
	size_t	k;

	*i += 2;
	k = 0;
	while (*(s + k))
	{
		*(str + *j) = *(s + k);
		(*j)++;
		k++;
	}
}

static void	print_num(char *str, size_t *i, size_t *j, int num)
{
	size_t	k;
	size_t	len;
	int		copy;

	*i += 2;
	copy = num;
	len = 1;
	while (copy /= 10)
		len++;
	k = 0;
	*j += len - 1;
	while (k != len)
	{
		*(str + *j - k) = num % 10 + '0';
		num /= 10;
		k++;
	}
	(*j)++;
}

int			print_out(const char *format, t_extract *spec, int count)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (count + 1))))
		return (-1);
	i = 0;
	j = 0;
	while (*(format + i))
	{
		while (*(format + i) != '%' && *(format + i) != '\0')
		{
			*(str + j) = *(format + i);
			i++;
			j++;
		}
		if (*(format + i) == '%' && *(format + i + 1) == 's')
			print_string(str, &i, &j, spec->str);
		if (*(format + i) == '%' && *(format + i + 1) == 'd')
			print_num(str, &i, &j, spec->num);
	}
	*(str + j) = '\0';
	write(1, str, count);
	free(str);
	return (0);
}
