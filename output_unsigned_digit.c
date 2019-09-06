/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_unsigned_digit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:04:56 by mgorczan          #+#    #+#             */
/*   Updated: 2019/04/20 15:05:03 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	unsigned_int_output(t_data data, unsigned long long int number)
{
	unsigned int	size;

	size = 0;
	if (data.widght == 0)
		return (putnbr_uns(number, lenght_dec(number), data.precision));
	if (data.alignment == '-')
	{
		size += putnbr_uns(number, lenght_dec(number), data.precision);
		if (data.precision != 0 || number != 0)
			data.widght -= (lenght_dec(number) > data.precision ?
							lenght_dec(number) : data.precision);
		if (data.widght > 0)
			while (data.widght-- > 0)
				size += f_putchar(' ');
		return (size);
	}
	if (data.precision != 0 || number != 0)
		data.widght -= (lenght_dec(number) > data.precision ?
						lenght_dec(number) : data.precision);
	if (data.widght > 0)
		while (data.widght-- > 0)
			size += f_putchar(data.alignment);
	size += putnbr_uns(number, lenght_dec(number), data.precision);
	return (size);
}

unsigned int	unsigned_xint_output(t_data data, unsigned long long int number)
{
	unsigned int	size;

	size = 0;
	if (data.widght == 0)
	{
		if (data.sharp == '#')
			size += f_putstr(data.upp_registr == 'a' ? "0x" : "0X", 2);
		return (size + putnbr_hex(number,
					lenght_hex(number), data, data.upp_registr));
	}
	if (data.alignment == '-')
	{
		if (data.sharp == '#')
			size += f_putstr(data.upp_registr == 'a' ? "0x" : "0X", 2);
		data.sharp = ' ';
		data.alignment = ' ';
		size += putnbr_hex(number,
		lenght_hex(number), data, data.upp_registr);
		size += output_hex_flags(data, number);
		return (size);
	}
	size += output_hex_flags(data, number);
	size += putnbr_hex(number, lenght_hex(number), data, data.upp_registr);
	return (size);
}

unsigned int	output_hex_flags(t_data data, unsigned long long int number)
{
	unsigned int size;

	size = 0;
	if (data.sharp == '#')
		if (data.alignment == '0')
			size += f_putstr(data.upp_registr == 'a' ? "0x" : "0X", 2);
	if (data.precision != 0 || number != 0)
		data.widght -= (lenght_hex(number) > data.precision ?
								lenght_hex(number) : data.precision);
	while (data.widght-- > 0)
		size += f_putchar(data.alignment);
	if (data.sharp == '#' && data.alignment != '0')
		size += f_putstr(data.upp_registr == 'a' ? "0x" : "0X", 2);
	return (size);
}

unsigned int	unsigned_oint_output(t_data data, unsigned long long int number)
{
	unsigned int	size;

	size = 0;
	if (data.widght == 0)
	{
		if (data.sharp == '#')
			size += f_putchar('0');
		return (size + putnbr_octal(number,
						lenght_octal(number), data.precision));
	}
	if (data.alignment == '-')
	{
		if (data.sharp == '#')
			size += f_putchar('0');
		data.sharp = ' ';
		data.alignment = ' ';
		size += putnbr_octal(number, lenght_octal(number), data.precision);
		return (size + output_octal_flags(data, number));
	}
	size += output_octal_flags(data, number);
	return (size + putnbr_octal(number, lenght_octal(number), data.precision));
}

unsigned int	output_octal_flags(t_data data, unsigned long long int number)
{
	unsigned int size;

	size = 0;
	if (data.precision != 0 || number != 0)
		data.widght -= (lenght_octal(number) > data.precision ?
		lenght_octal(number) : data.precision);
	while (data.widght-- > 0)
		size += f_putchar(data.alignment);
	if (data.sharp == '#')
		size += f_putchar('0');
	return (size);
}
