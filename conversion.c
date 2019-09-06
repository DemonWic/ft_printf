/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:58:48 by mgorczan          #+#    #+#             */
/*   Updated: 2019/04/18 17:58:58 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long int	conversion_unsigned_type(const char *format,
						unsigned long long int digit, char spec)
{
	unsigned int	i;
	char			lenght;

	i = 0;
	lenght = ' ';
	while (format[i] != '\0' && format[i] != spec)
	{
		lenght = search_type(format, &i);
		if (lenght == 'j' || lenght == 'z' || lenght == 'l' + 1)
			return (digit);
	}
	if (lenght == 'l' || format[i] == 'U' || format[i] == 'O')
		return (digit);
	if (lenght == 'h')
		return ((unsigned short int)digit);
	if (lenght == ('h' + 1))
		return ((unsigned char)digit);
	return ((unsigned int)digit);
}

long long int			conversion_sign_type(const char *format,
						long long int digit, char spec)
{
	unsigned int	i;
	char			lenght;

	i = 0;
	lenght = ' ';
	while (format[i] != '\0' && format[i] != spec)
	{
		lenght = search_type(format, &i);
		if (lenght == 'j' || lenght == 'z' || lenght == 'l' + 1)
			return (digit);
	}
	if (lenght == 'l' || format[i] == 'D')
		return (digit);
	if (lenght == 'h')
		return ((short int)digit);
	if (lenght == ('h' + 1))
		return ((char)digit);
	return ((int)digit);
}

char					search_type(const char *format, unsigned int *i)
{
	char	lenght;

	lenght = ' ';
	if (format[*i] == 'j')
		return ('j');
	if (format[*i] == 'z')
		return ('z');
	if (format[*i] == 'l')
	{
		if (format[++(*i)] == 'l')
			return ('l' + 1);
		else
			return ('l');
	}
	if (format[*i] == 'h' && lenght != 'l')
	{
		if (format[++(*i)] == 'h')
		{
			++(*i);
			return ('h' + 1);
		}
		return ('h');
	}
	++(*i);
	return (lenght);
}
