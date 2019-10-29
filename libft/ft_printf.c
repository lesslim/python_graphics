/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:26:51 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 20:40:06 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	number(va_list ap, size_t *i, t_extract **spec)
{
	size_t	len;
	int		num;

	*i += 2;
	(*spec)->num = va_arg(ap, int);
	len = 1;
	num = (*spec)->num;
	while (num /= 10)
		len++;
	return ((int)len);
}

static int	ft_string(va_list ap, size_t *i, t_extract **spec)
{
	size_t	len;

	*i += 2;
	(*spec)->str = va_arg(ap, char *);
	len = ft_strlen((*spec)->str);
	return ((int)len);
}

static int	ft_format(const char *format, va_list ap)
{
	size_t		i;
	size_t		n;
	t_extract	*spec;
	int			count;

	i = 0;
	count = 0;
	if (!(spec = (t_extract *)malloc(sizeof(t_extract))))
		return (-1);
	while (*(format + i))
	{
		n = 0;
		while (*(format + i + n) != '%' && *(format + i + n) != '\0')
			n++;
		i += n;
		count += n;
		if (*(format + i) == '%' && *(format + i + 1) == 'd')
			count += number(ap, &i, &spec);
		if (*(format + i) == '%' && *(format + i + 1) == 's')
			count += ft_string(ap, &i, &spec);
	}
	if (print_out(format, spec, count))
		return (-1);
	free(spec);
	return (count);
}

int			light_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		exit(-1);
	count = 0;
	va_start(ap, format);
	count = ft_format(format, ap);
	va_end(ap);
	return (count);
}
