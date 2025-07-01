NAME = so_long
CC = cc
CFLAGS = -Werror -Wall -Wextra  -g -I. -I.. -Iminilibx-linux
SRC_FOLDER = src
BNS_FOLDER = bonus
SRCS = $(addprefix $(SRC_FOLDER)/, main.c parsing.c map_validation.c map_validation2.c images.c game.c)
BNS = $(addprefix $(BNS_FOLDER)/, main_bonus.c parsing_bonus.c map_validation_bonus.c map_validation2_bonus.c images_bonus.c game_bonus.c) 
OBJS = $(SRCS:.c=.o)
BNS_OBJS = $(BNS:.c=.o)
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)

	@make -s -C Libft
	@cp ./Libft/libft.a .
	@make -C minilibx-linux
	@$(CC) $(CFLAGS) $(OBJS) libft.a $(MLX_FLAGS) -o $(NAME)
	@echo 'Biblioteca criada'
	@echo 'Codigo compilado!'

mlx:
	@git clone https://github.com/42Paris/minilibx-linux.git

bonus:
	@$(CC) $(CFLAGS) $(BNS_OBJS) libft.a $(MLX_FLAGS) -o $(NAME)

clean:
	@find . -name '*.o' -delete
	@echo 'Objetos limpos!'

fclean: clean
	@rm -f $(NAME)
	@rm -f libft.a
	@echo  'Biblioteca limpa!'

re: fclean all