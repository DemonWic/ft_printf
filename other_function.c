/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:55:07 by mgorczan          #+#    #+#             */
/*   Updated: 2019/04/10 17:55:22 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				conversion_digit(const char *format, unsigned int *i)
{
	int	number;

	number = 0;
	while (format[*i] != '\0' && format[*i] >= '0' && format[*i] <= '9')
	{
		number = 10 * number + format[*i] - '0';
		++(*i);
	}
	return (number);
}

unsigned int	f_strlen(const char *s)
{
	unsigned int size;

	size = 0;
	while (s[size] != '\0')
		++size;
	return (size);
}

unsigned int	lenght_dec(unsigned long long int number)
{
	unsigned int lenght;

	lenght = 0;
	if (number == 0)
		++lenght;
	while (number != 0)
	{
		number /= 10;
		++lenght;
	}
	return (lenght);
}

unsigned int	lenght_hex(unsigned long long int number)
{
	int lenght;

	lenght = 1;
	while (number > 15)
	{
		number /= 16;
		++lenght;
	}
	return (lenght);
}

unsigned int	lenght_octal(unsigned long long int number)
{
	int lenght;

	lenght = 1;
	while (number > 7)
	{
		number /= 8;
		++lenght;
	}
	return (lenght);
}
