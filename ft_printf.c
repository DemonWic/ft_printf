/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:05:40 by mgorczan          #+#    #+#             */
/*   Updated: 2019/04/09 21:24:23 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	unsigned int	i;
	unsigned int	size;
	va_list			argptr;

	i = 0;
	size = 0;
	va_start(argptr, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			++i;
			size += specifier(&format[i], argptr,
					determinator_spec(format, &i));
			if (format[i] != '\0')
				++i;
		}
		else
			size += f_putchar(format[i++]);
	}
	va_end(argptr);
	return (size);
}

char			determinator_spec(const char *format, unsigned int *i)
{
	while (format[*i] != '\0')
	{
		if (format[*i] == '%' || format[*i] == 's' || format[*i] == 'p')
			return (format[*i]);
		if (format[*i] == 'c' || format[*i] == 'C')
			return (format[*i]);
		if (format[*i] == 'u' || format[*i] == 'U')
			return (format[*i]);
		if (format[*i] == 'o' || format[*i] == 'O')
			return (format[*i]);
		if (format[*i] == 'x' || format[*i] == 'X')
			return (format[*i]);
		if (format[*i] == 'd' || format[*i] == 'D' || format[*i] == 'i')
			return (format[*i]);
		if (format[*i] == 'f' || format[*i] == 'F')
			return (format[*i]);
		if ((format[*i] >= 'A' && format[*i] <= 'Z'
							&& format[*i] != 'L') || format[*i] == '}')
			return (format[*i]);
		++(*i);
	}
	return (0);
}

unsigned int	specifier(const char *format, va_list argptr, char spec)
{
	if (spec == 'c' || spec == 'C')
		return (symbol(format, argptr, spec));
	if (spec == 's')
		return (line(format, argptr, 's'));
	if (spec == 'u' || spec == 'U')
		return (unsigned_dec_int(format, argptr, spec));
	if (spec == 'o' || spec == 'O')
		return (unsigned_octal_int(format, argptr, spec));
	if (spec == 'x' || spec == 'X')
		return (unsigned_hex_int(format, argptr, spec));
	if (spec == 'd' || spec == 'D' || spec == 'i')
		return (sign_dec_int(format, argptr, spec));
	if (spec == 'p')
		return (pointer(format, argptr, spec));
	if (spec == 'f' || spec == 'F')
		return (float_int(format, argptr, spec));
	if ((spec >= 'A' && spec <= 'Z') || spec == '}' || spec == '%')
		return (special_symbol(format, spec));
	return (0);
}
