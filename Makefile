NAME = libftprintf.a
SRC = ft_printf.c  other_function.c output.c flags_and_precision.c output_symbol.c output_unsigned_digit.c output_sign_digit.c specifiers_digit.c specifiers_symbol.c conversion.c output_float.c specifiers_float.c
OBJ = ft_printf.o  other_function.o output.o flags_and_precision.o output_symbol.o output_unsigned_digit.o output_sign_digit.o specifiers_digit.o specifiers_symbol.o conversion.o output_float.o specifiers_float.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
clean:
	@/bin/rm -f $(OBJ)
fclean: clean
	@/bin/rm -f $(NAME)
re: fclean all clean
