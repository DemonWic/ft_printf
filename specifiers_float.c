/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:40:37 by mgorczan          #+#    #+#             */
/*   Updated: 2019/04/27 19:40:38 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	float_int(const char *format, va_list argptr, char spec)
{
	long double		number;
	t_data			data;
	unsigned int	size;
	double			nu2;

	size = 0;
	data.alignment = f_alignment(format, spec);
	data.widght = f_widght(format, spec);
	data.sign = f_sign(format, spec);
	data.precision = f_precision(format, spec);
	data.sharp = f_sharp(format, spec);
	number = conversion_double(format, argptr, spec);
	nu2 = (double)number;
	if (nu2 == 0 && (*(long int*)&nu2 >> 63))
	{
		++data.lenght;
		data.sign = '-';
	}
	if (data.precision == -1)
		data.precision = 6;
	if (number < 0 && f_check(number, spec, 0, '0') == 0)
		data.sign = '-';
	data.lenght = lenght_char_float(number, spec, data);
	size += sign_double_output(data, number, spec);
	return (size);
}

long double		conversion_double(const char *format, va_list argptr, char spec)
{
	unsigned int i;

	i = 0;
	while (format[i] != '\0' && format[i] != spec)
	{
		if (format[i] == 'L')
			return (va_arg(argptr, long double));
		++i;
	}
	return (va_arg(argptr, double));
}

unsigned int	lenght_char_float(long double number, char spec, t_data data)
{
	unsigned int	size;

	size = 0;
	if (f_check(number, spec, 0, data.sign) != 0)
		return (f_check(number, spec, 0, data.sign));
	if ((data.sign == '-' || data.sign == '+' || data.sign == ' ')
								&& f_check(number, spec, 0, '0') == 0)
		++size;
	if (data.precision == 0 && data.sharp == '#')
		++size;
	if ((long int)number == 0)
		++size;
	while (number <= -1 || number >= 1)
	{
		number /= 10;
		++size;
	}
	if (data.precision == -1)
		return (size + 7);
	if (data.precision != 0)
		return (size + 1 + data.precision);
	return (size);
}

long double		f_round(long double number, long int precision)
{
	int			i;
	long int	buff;

	i = precision;
	while (precision-- > -1)
	{
		buff = (long int)number;
		number = (number - (long int)number) * 10;
	}
	if (number == 5 || number == -5)
	{
		if (buff % 2 == 0)
		{
			number = (long int)number % 10;
			while (i-- > -1)
				number /= 10;
			return (-number);
		}
	}
	number = (long int)number % 10;
	while (i-- > -1)
		number /= 10;
	return (number);
}

unsigned int	f_check(long double number, char spec, int flag, char sign)
{
	unsigned int size;

	size = 0;
	if (number == (1.0 / 0.0))
	{
		if (sign == '+' || sign == ' ')
		{
			if (flag != 0)
				f_putchar(sign);
			else
				++size;
		}
		size += print_check("inf", spec, flag);
	}
	else if (number == (-1.0 / 0.0))
	{
		size += print_check("-inf", spec, flag);
	}
	else if (number != number)
	{
		size += print_check("nan", spec, flag);
	}
	return (size);
}
