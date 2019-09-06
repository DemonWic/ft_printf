/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:49:19 by mgorczan          #+#    #+#             */
/*   Updated: 2019/04/26 14:49:21 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	sign_double_output(t_data data, long double number, char spec)
{
	unsigned int	size;

	size = 0;
	if (data.alignment == '0' && f_check(number, spec, 0, '0') != 0)
		data.alignment = ' ';
	if (data.widght == 0)
	{
		if (!f_check(number, spec, 1, data.sign))
			putnbr_double(number, data);
		return (data.lenght);
	}
	if (data.alignment == '-')
	{
		if (!f_check(number, spec, 1, data.sign))
			putnbr_double(number, data);
		data.widght -= data.lenght;
		while (data.widght-- > 0)
			size += f_putchar(' ');
		return (size + data.lenght);
	}
	return (output_sign_double_flags(data, number, spec));
}

unsigned int	output_sign_double_flags(t_data data, double number, char spec)
{
	unsigned int	size;

	size = 0;
	if ((data.sign == '+' || data.sign == ' ' || data.sign == '-')
											&& data.alignment == '0')
	{
		size += f_putchar(data.sign);
		--data.lenght;
		--data.widght;
		data.sign = '0';
	}
	data.widght -= data.lenght;
	while (data.widght-- > 0)
		size += f_putchar(data.alignment);
	if (!f_check(number, spec, 1, data.sign))
		putnbr_double(number, data);
	return (size + data.lenght);
}

unsigned int	putnbr_double(long double number, t_data data)
{
	long int	size;
	double		buff;

	size = 0;
	if (data.sign == '-' || data.sign == '+' || data.sign == ' ')
	{
		f_putchar(data.sign);
		--data.lenght;
	}
	number += f_round(number, data.precision);
	buff = (long int)number;
	while (buff <= -1 || buff >= 1)
	{
		buff /= 10;
		++size;
	}
	return (putnbr_double_support(number, data, buff, size));
}

long int		putnbr_double_support(long double number,
							t_data data, double buff, long int size)
{
	buff = (long int)number;
	number -= (long int)number;
	if (buff == 0)
		size += f_putchar('0');
	else
		putnbr((long int)buff, size, size);
	data.lenght -= size;
	if (data.lenght > 0)
	{
		data.lenght -= f_putchar('.');
		while (data.lenght--)
		{
			number *= 10;
			f_putchar('0' + (number > 0 ?
					(long int)number : -(long int)number));
			number -= (long int)number;
		}
	}
	else
	{
		if (data.sharp == '#')
			return (f_putchar('.'));
	}
	return (0);
}

unsigned int	print_check(char *s, char spec, int flag)
{
	unsigned int	size;

	size = 0;
	if (flag == 0)
		return (f_strlen(s));
	while (*s != '\0')
	{
		if (*s == '-')
			size += f_putchar('-');
		else if (spec == 'F')
			size += f_putchar(*s - 32);
		else
			size += f_putchar(*s);
		++s;
	}
	return (size);
}
