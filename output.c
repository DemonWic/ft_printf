/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:05:14 by mgorczan          #+#    #+#             */
/*   Updated: 2019/04/10 16:05:22 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	putnbr(long long int number,
				unsigned int number_lenght, long int precision)
{
	unsigned int	size;

	size = 0;
	if (precision == 0 && number == 0)
		return (0);
	if (precision > number_lenght)
	{
		precision = precision - number_lenght;
		while (precision > 0)
		{
			size += f_putchar('0');
			--precision;
		}
	}
	if (!(number > -10 && number < 10))
		size += putnbr(number / 10, number_lenght, precision);
	size += (number >= 0 ? f_putchar(number % 10 + '0') :
							f_putchar(-1 * (number % 10 - '0')));
	return (size);
}

unsigned int	putnbr_uns(unsigned long long int number,
				unsigned int number_lenght, long int precision)
{
	unsigned int	size;

	size = 0;
	if (precision == 0 && number == 0)
		return (0);
	if (precision > number_lenght)
	{
		precision = precision - number_lenght;
		while (precision-- > 0)
			size += f_putchar('0');
	}
	if (number > 9)
		size += putnbr_uns(number / 10, number_lenght, precision);
	size += (number > 9 ?
			f_putchar(number % 10 + '0') : f_putchar(number + '0'));
	return (size);
}

unsigned int	putnbr_hex(unsigned long long int number,
				unsigned int number_lenght, t_data data, char spec)
{
	unsigned int	size;

	size = 0;
	if (data.precision == 0 && number == 0)
		return (0);
	if (data.precision > number_lenght)
	{
		data.precision = data.precision - number_lenght;
		while (data.precision-- > 0)
			size += f_putchar('0');
	}
	if (number < 10)
		size += f_putchar(number + '0');
	else if (number > 9 && number < 16)
		size += f_putchar(number % 10 + spec);
	else
	{
		size += putnbr_hex(number / 16, number_lenght, data, spec);
		if (number % 16 < 10)
			size += f_putchar((number % 16) + '0');
		else if ((number % 16 > 9) && ((number % 16) < 16))
			size += f_putchar((number % 16) % 10 + spec);
	}
	return (size);
}

unsigned int	putnbr_octal(unsigned long long int number,
				unsigned int number_lenght, long int precision)
{
	unsigned int size;

	size = 0;
	if (precision == 0 && number == 0)
		return (0);
	if (precision > number_lenght)
	{
		precision = precision - number_lenght;
		while (precision > 0)
		{
			size += f_putchar('0');
			--precision;
		}
	}
	if (number < 8)
		size += f_putchar(number + '0');
	else
	{
		size += putnbr_octal(number / 8, number_lenght, precision);
		size += f_putchar(number % 8 + '0');
	}
	return (size);
}
