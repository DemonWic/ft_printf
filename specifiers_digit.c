/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_digit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:53:25 by mgorczan          #+#    #+#             */
/*   Updated: 2019/04/18 17:53:35 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	sign_dec_int(const char *format, va_list argptr, char spec)
{
	long long int	number;
	t_data			data;
	unsigned		size;

	size = 0;
	data.alignment = f_alignment(format, spec);
	data.widght = f_widght(format, spec);
	data.precision = f_precision(format, spec);
	data.sign = f_sign(format, spec);
	number = conversion_sign_type(format, va_arg(argptr, long long int), spec);
	if (data.precision > -1 && data.alignment == '0')
		data.alignment = ' ';
	if (number < 0)
		data.sign = '-';
	if (data.sign == '-' || data.sign == '+' || data.sign == ' ')
		--data.widght;
	size += sign_int_output(data, number);
	return (size);
}

unsigned int	unsigned_dec_int(const char *format, va_list argptr, char spec)
{
	unsigned long long int	number;
	t_data					data;
	unsigned int			size;

	size = 0;
	data.alignment = f_alignment(format, spec);
	data.widght = f_widght(format, spec);
	data.precision = f_precision(format, spec);
	number = conversion_unsigned_type(format,
				va_arg(argptr, unsigned long long int), spec);
	if (data.precision > -1 && data.alignment == '0')
		data.alignment = ' ';
	size += unsigned_int_output(data, number);
	return (size);
}

unsigned int	unsigned_hex_int(const char *format, va_list argptr, char spec)
{
	unsigned long long int	number;
	unsigned int			size;
	t_data					data;

	size = 0;
	data.alignment = f_alignment(format, spec);
	data.widght = f_widght(format, spec);
	data.precision = f_precision(format, spec);
	data.sharp = f_sharp(format, spec);
	number = conversion_unsigned_type(format,
				va_arg(argptr, unsigned long long int), spec);
	if (data.precision > -1 && data.alignment == '0')
		data.alignment = ' ';
	if (data.sharp == '#' && number == 0)
		data.sharp = ' ';
	if (data.sharp == '#')
		data.widght -= 2;
	data.upp_registr = spec == 'x' ? 'a' : 'A';
	size += unsigned_xint_output(data, number);
	return (size);
}

unsigned int	unsigned_octal_int(const char *format,
				va_list argptr, char spec)
{
	unsigned long long int	number;
	t_data					data;

	data.alignment = f_alignment(format, spec);
	data.widght = f_widght(format, spec);
	data.precision = f_precision(format, spec);
	data.sharp = f_sharp(format, spec);
	number = conversion_unsigned_type(format,
				va_arg(argptr, unsigned long long int), spec);
	if (data.precision > -1 && data.alignment == '0')
		data.alignment = ' ';
	if (data.sharp == '#' && number == 0)
	{
		if (data.precision == 0)
			++data.precision;
		else
			data.sharp = ' ';
	}
	if (data.sharp == '#')
	{
		--data.precision;
		--data.widght;
	}
	return (unsigned_oint_output(data, number));
}
