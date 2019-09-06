/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgorczan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:42:12 by mgorczan          #+#    #+#             */
/*   Updated: 2019/04/08 14:42:26 by mgorczan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# define ABS(x) (x < 0 ? -1 * x : x)

typedef struct			s_data
{
	char				alignment;
	long int			widght;
	long int			precision;
	long int			lenght;
	char				sharp;
	char				sign;
	char				upp_registr;
}						t_data;
unsigned long long int	conversion_unsigned_type(const char *format,
						unsigned long long int digit, char spec);
long long int			conversion_sign_type(const char *format,
						long long int digit, char spec);
char					search_type(const char *format, unsigned int *i);
char					f_alignment(const char *format, char spec);
unsigned int			f_widght(const char *format, char spec);
char					f_sign(const char *format, char spec);
char					f_sharp(const char *format, char spec);
long int				f_precision(const char *format, char spec);
int						ft_printf(const char *format, ...);
char					determinator_spec(const char *format, unsigned int *i);
unsigned int			specifier(const char *format,
						va_list argptr, char spec);
int						conversion_digit(const char *format, unsigned int *i);
unsigned int			f_strlen(const char *s);
unsigned int			lenght_dec(unsigned long long int number);
unsigned int			lenght_hex(unsigned long long int number);
unsigned int			lenght_octal(unsigned long long int number);
unsigned int			sign_int_output(t_data data, long long int number);
unsigned int			unsigned_int_output(t_data data,
						unsigned long long int number);
unsigned int			unsigned_xint_output(t_data data,
						unsigned long long int number);
unsigned int			unsigned_oint_output(t_data data,
						unsigned long long int number);
unsigned int			output_hex_flags(t_data data,
						unsigned long long int number);
unsigned int			output_octal_flags(t_data data,
						unsigned long long int number);
unsigned int			output_sign_flags(t_data data, long long int number);
unsigned int			line_output(t_data data, char *line);
unsigned int			symbol_output(t_data data, char symbol);
unsigned int			f_putstr(const char *s, unsigned int size);
unsigned int			f_putchar(char c);
unsigned int			putnbr(long long int number,
						unsigned int number_lenght, long int precision);
unsigned int			putnbr_uns(unsigned long long int number,
						unsigned int number_lenght, long int precision);
unsigned int			putnbr_hex(unsigned long long int number,
						unsigned int number_lenght, t_data data, char spec);
unsigned int			putnbr_octal(unsigned long long int number,
						unsigned int number_lenght, long int precision);
unsigned int			sign_dec_int(const char *format,
						va_list argptr, char spec);
unsigned int			unsigned_dec_int(const char *format,
						va_list argptr, char spec);
unsigned int			unsigned_hex_int(const char *format,
						va_list argptr, char spec);
unsigned int			unsigned_octal_int(const char *format,
						va_list argptr, char spec);
unsigned int			pointer(const char *format, va_list argptr, char spec);
unsigned int			symbol(const char *format, va_list argptr, char spec);
unsigned int			special_symbol(const char *format, char spec);
unsigned int			line(const char *format, va_list argptr, char spec);
unsigned int			float_int(const char *format,
													va_list argptr, char spec);
unsigned int			sign_double_output(t_data data,
												long double number, char spec);
unsigned int			output_sign_double_flags(t_data data,
													double number, char spec);
unsigned int			f_check(long double number,
												char spec, int flag, char sign);
unsigned int			lenght_char_float(long double number,
														char spec, t_data data);
unsigned int			putnbr_double(long double number, t_data data);
long int				putnbr_double_support(long double number,
									t_data data, double buff, long int size);
long double				f_powd(long double nb, long int p);
long double				f_round(long double number, long int precision);
long double				conversion_double(const char *format,
											va_list argptr, char spec);
unsigned int			print_check(char *s, char spec, int flag);
#endif
