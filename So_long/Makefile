NAME = so_long
CC = cc
CFLAGS = -Werror -Wall -Wextra  -g
SRC_FOLDER = src
SRCS = $(addprefix $(SRC_FOLDER)/, main.c parsing.c errors_handling.c)
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)

	@make -s -C Libft
	@cp ./Libft/libft.a .
	@$(CC) $(CFLAGS) $(OBJS) -L. -lft -o $(NAME)
	@echo 'Biblioteca criada'
	@echo 'Codigo compilado!'

%.o:%.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@
 
clean:
	@find . -name '*.o' -delete
	@echo 'Objetos limpos!'

fclean: clean
	@rm -f $(NAME)
	@echo  'Biblioteca limpa!'

re: fclean all