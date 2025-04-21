NAME = libft.a
CC = cc
CFLAGS = -Werror -Wall -Wextra -g #-fsanitize=address
SRCS = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
ft_memcpy.c  ft_memmove.c  ft_memset.c  ft_strlcat.c  ft_strlcpy.c  ft_strlen.c\
ft_toupper.c ft_tolower.c ft_strchr.c ft_strdup.c ft_atoi.c ft_strrchr.c\
ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_substr.c\
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
 ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c
#ft_lstiter_bonus.c ft_lstmap_bonus.c 
BONUS_OBJS = $(BONUS:.c=.o);
OBJS = $(SRCS:.c=.o)
MAIN = main

all: $(NAME) $(MAIN)

$(NAME): $(OBJS) 
	@ar rcs $(NAME) $(OBJS)
	@echo 'Biblioteca criada'
	@echo 'Codigo compilado!'
bonus:.bonus

.bonus: $(OBJS) $(BONUS_OBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@touch .bonus
	@echo 'Bonus criado'

$(MAIN): $(NAME)
	@$(CC) $(CFLAGS) -I. $(MAIN).c -L. -lft $< -o $@ 


%.o:%.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@
 
clean:
	@rm -f $(OBJS) $(MAIN) $(BONUS_OBJS)
	@echo 'Objetos limpos!'

fclean: clean
	@rm -f $(NAME)
	@echo  'Biblioteca limpa!'

re: fclean all