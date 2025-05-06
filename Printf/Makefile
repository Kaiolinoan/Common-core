NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Werror -Wextra -g
SRCS = ft_printf.c print_char.c print_hex.c \
print_numbers.c print_pointer.c print_str.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Biblioteca criada"

%.o:%.c
	@$(CC) $(FLAGS) -I. -c $< -o $@

clean: 
	@rm -f $(OBJS)
	@echo "Objetos limpos"

fclean: clean
	@rm -f $(NAME)
	@echo "Biblioteca limpa"

re: fclean all