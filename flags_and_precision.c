/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_and_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:04:56 by mgorczan          #+#    #+#             */
/*   Updated: 2019/04/18 17:05:04 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			f_alignment(const char *format, char spec)
{
	char			alignment;
	unsigned int	i;

	i = 0;
	alignment = ' ';
	while (format[i] != '\0' && format[i] != spec)
	{
		if (format[i] == '-')
			return ('-');
		if (format[i] == '.')
		{
			if (format[++i] == '-')
				return ('-');
			conversion_digit(format, &i);
		}
		else if (format[i] > '0' && format[i] < '9')
		{
			++i;
			conversion_digit(format, &i);
		}
		else if (format[i++] == '0')
			alignment = '0';
	}
	return (alignment);
}

unsigned int	f_widght(const char *format, char spec)
{
	unsigned int	i;
	unsigned int	widght;

	i = 0;
	widght = 0;
	while (format[i] != '\0' && format[i] != spec)
	{
		if (format[i] != '.')
		{
			if (format[i] > '0' && format[i] <= '9')
				widght = conversion_digit(format, &i);
			else
				++i;
		}
		else
		{
			++i;
			conversion_digit(format, &i);
		}
	}
	return (widght);
}

char			f_sign(const char *format, char spec)
{
	unsigned int	i;
	char			sign;

	i = 0;
	sign = '0';
	while (format[i] != '\0' && format[i] != spec)
	{
		if (format[i] == '+')
			return ('+');
		if (format[i] == ' ')
			sign = ' ';
		++i;
	}
	return (sign);
}

char			f_sharp(const char *format, char spec)
{
	unsigned int i;

	i = 0;
	while (format[i] != '\0' && format[i] != spec)
	{
		if (format[i] == '#')
			return ('#');
		++i;
	}
	return (' ');
}

long int		f_precision(const char *format, char spec)
{
	unsigned int	i;
	long int		precision;

	i = 0;
	precision = -1;
	while (format[i] != '\0' && format[i] != spec)
	{
		if (format[i] == '.')
		{
			++i;
			precision = conversion_digit(format, &i);
		}
		else
			++i;
	}
	return (precision);
}
