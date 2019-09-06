/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_sign_digit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:05:35 by mgorczan          #+#    #+#             */
/*   Updated: 2019/04/20 15:05:43 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	sign_int_output(t_data data, long long int number)
{
	unsigned int	size;

	size = 0;
	if (data.widght == 0)
	{
		if (number < 0)
			size += f_putchar('-');
		else if (data.sign == '+' || data.sign == ' ')
			size += f_putchar(data.sign);
		return (size + putnbr(number, lenght_dec(ABS(number)), data.precision));
	}
	if (data.alignment == '-')
	{
		if (data.sign == '+' || data.sign == ' ' || data.sign == '-')
			size += f_putchar(data.sign);
		size += putnbr(number, lenght_dec(ABS(number)), data.precision);
		if (data.precision != 0 || number != 0)
			data.widght -= (lenght_dec(ABS(number)) > data.precision ?
							lenght_dec(ABS(number)) : data.precision);
		while (data.widght-- > 0)
			size += f_putchar(' ');
		return (size);
	}
	size += output_sign_flags(data, number);
	return (size + putnbr(number, lenght_dec(ABS(number)), data.precision));
}

unsigned int	output_sign_flags(t_data data, long long int number)
{
	unsigned int size;

	size = 0;
	if ((data.sign == '+' || data.sign == ' ' || data.sign == '-')
											&& data.alignment == '0')
		size += f_putchar(data.sign);
	if (data.precision != 0 || number != 0)
		data.widght -= (lenght_dec(ABS(number)) > data.precision ?
							lenght_dec(ABS(number)) : data.precision);
	while (data.widght-- > 0)
		size += f_putchar(data.alignment);
	if ((data.sign == '+' || data.sign == ' ' || data.sign == '-')
											&& data.alignment != '0')
		size += f_putchar(data.sign);
	return (size);
}
