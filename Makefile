NAME = pipex
SRC_FILE = error_handlers.c \
	execute_cmds.c \
	ft_close_free.c \
	handle_heredoc.c \
	main.c \
	parse_cmd.c
SRCS = $(addprefix src/, $(SRC_FILE))
ifdef BONUS
	SRCS += bonus/init_pipex_bonus.c
else
	SRCS += src/init_pipex.c
endif
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./includes -I ./libft
LIBFT = libft/libft.a
LIBFT_DIR = libft

all: $(NAME)

$(NAME): $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

bonus:
	make BONUS=1

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus