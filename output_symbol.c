/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_symbol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:43:37 by mgorczan          #+#    #+#             */
/*   Updated: 2019/04/18 17:43:43 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	line_output(t_data data, char *line)
{
	unsigned int	size;

	size = 0;
	if (data.widght == 0)
		return (f_putstr(line, data.precision));
	if (data.alignment == '-')
	{
		size += f_putstr(line, data.precision);
		data.widght -= (f_strlen(line) > data.precision ?
						data.precision : f_strlen(line));
		if (data.widght > 0)
			while ((data.widght)-- > 0)
				size += f_putchar(' ');
	}
	else
	{
		data.widght -= (f_strlen(line) > data.precision ?
						data.precision : f_strlen(line));
		if (data.widght > 0)
			while ((data.widght)-- > 0)
				size += f_putchar(data.alignment);
		size += f_putstr(line, data.precision);
	}
	return (size);
}

unsigned int	symbol_output(t_data data, char symbol)
{
	unsigned int	size;

	size = 0;
	if (data.widght == 0)
	{
		size += f_putchar(symbol);
	}
	else
	{
		if (data.alignment == '-')
		{
			size += f_putchar(symbol);
			if (data.widght > 0)
				while (--data.widght > 0)
					size += f_putchar(' ');
		}
		else
		{
			if (data.widght > 0)
				while (--data.widght > 0)
					size += f_putchar(data.alignment);
			size += f_putchar(symbol);
		}
	}
	return (size);
}

unsigned int	f_putstr(const char *s, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (s[i] && i < size)
		write(1, &s[i++], 1);
	return (i);
}

unsigned int	f_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
