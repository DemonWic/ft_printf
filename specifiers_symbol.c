/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_symbol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:54:35 by mgorczan          #+#    #+#             */
/*   Updated: 2019/04/18 17:54:42 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	symbol(const char *format, va_list argptr, char spec)
{
	unsigned int	size;
	t_data			data;
	int				c;

	size = 0;
	data.alignment = f_alignment(format, spec);
	data.widght = f_widght(format, spec);
	c = va_arg(argptr, int);
	size += symbol_output(data, c);
	return (size);
}

unsigned int	special_symbol(const char *format, char spec)
{
	unsigned int	size;
	t_data			data;

	size = 0;
	data.alignment = f_alignment(format, spec);
	data.widght = f_widght(format, spec);
	size += symbol_output(data, spec);
	return (size);
}

unsigned int	line(const char *format, va_list argptr, char spec)
{
	unsigned int	size;
	t_data			data;
	char			*line;

	size = 0;
	data.alignment = f_alignment(format, spec);
	data.widght = f_widght(format, spec);
	data.precision = f_precision(format, spec);
	line = va_arg(argptr, char*);
	if (line == NULL)
		line = "(null)";
	if (data.precision == -1)
		data.precision = f_strlen(line);
	size += line_output(data, line);
	return (size);
}

unsigned int	pointer(const char *format, va_list argptr, char spec)
{
	unsigned long long int	number;
	unsigned int			size;
	t_data					data;

	size = 0;
	data.alignment = f_alignment(format, spec);
	data.widght = f_widght(format, spec);
	data.precision = f_precision(format, spec);
	number = va_arg(argptr, unsigned long long int);
	if (data.precision > -1 && data.alignment == '0')
		data.alignment = ' ';
	data.sharp = '#';
	data.widght -= 2;
	data.upp_registr = 'a';
	size += unsigned_xint_output(data, number);
	return (size);
}
