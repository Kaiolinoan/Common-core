NAME = so_long
CC = cc
CFLAGS = -Werror -Wall -Wextra  -g -I. -I.. -Iminilibx-linux
SRC_FOLDER = src
SRCS = $(addprefix $(SRC_FOLDER)/, main.c parsing.c errors_handling.c errors_handling2.c images.c move.c)
OBJS = $(SRCS:.c=.o)
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)

	@make -s -C Libft
	@cp ./Libft/libft.a .
	@make -C minilibx-linux
	@$(CC) $(CFLAGS) $(OBJS) libft.a $(MLX_FLAGS) -o $(NAME)
	@echo 'Biblioteca criada'
	@echo 'Codigo compilado!'

%.o:%.c
	
	@$(CC) $(CFLAGS) -I. -c -Imlx_linux -O3 -c $< -o $@

mlx:
	@git clone https://github.com/42Paris/minilibx-linux.git
 
clean:
	@find . -name '*.o' -delete
	@echo 'Objetos limpos!'

fclean: clean
	@rm -f $(NAME)
	@rm -f libft.a
	@echo  'Biblioteca limpa!'

re: fclean all