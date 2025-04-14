NAME = libft.a
CC = cc
CFLAGS = -Werror -Wall -Wextra -g
SRCS = $(filter-out main.c, $(wildcard *.c))
OBJS = $(SRCS:.c=.o)
MAIN = main

all: $(NAME) $(MAIN)

$(NAME): $(OBJS) 
	@ar rcs $(NAME) $(OBJS)
	@echo 'Biblioteca criada'
	@echo 'Codigo compilado!'


$(MAIN): $(NAME)
	@$(CC) $(CFLAGS) -I. $(MAIN).c -L. -lft $< -o $@
	@echo 'Main compilado!'


%.o:%.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@
 
clean:
	@rm -f $(OBJS) $(MAIN)
	@echo 'Objetos limpos!'

fclean: clean
	@rm -f $(NAME)
	@echo  'Biblioteca limpa!'

re: fclean all