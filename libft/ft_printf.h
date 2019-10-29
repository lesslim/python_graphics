/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:35:34 by nhamill           #+#    #+#             */
/*   Updated: 2019/10/18 20:40:30 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct		s_extract
{
	int				num;
	char			*str;
}					t_extract;

int					print_out(const char *format, t_extract *spec, int count);
int					light_printf(const char *format, ...);

#endif
