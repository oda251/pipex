NAME = pipex
SRCS = main.c \
	init_pipex.c \
	handle_heredoc.c \
	execute_cmds.c \
	parse_cmd.c \
	ft_close_free.c \
	error_handlers.c
BONUS_SRCS = main.c \
	init_pipex_bonus.c \
	handle_heredoc.c \
	execute_cmds.c \
	parse_cmd.c \
	ft_close_free.c \
	error_handlers.c
SRC_DIR = ./src/
ifdef BONUS
	SRC = $(addprefix $(SRC_DIR), $(BONUS_SRCS))
else
	SRC = $(addprefix $(SRC_DIR), $(SRCS))
endif
INCLUDES = -I ./includes/ -I ./libft/ -I ./ft_get_next_line/
LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
ifeq ($(UNAME_S), Linux)
	CC = gcc
else
	CC = cc
endif
CFLAGS = -Wall -Wextra -Werror
TFLAGS = -Wall -Wextra -fsanitize=address

all: $(NAME)

$(NAME): $(LIBFT) $(SRC)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) -L $(LIBFT_DIR) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

bonus: $(LIBFT) $(BONUS_SRC)
	@make BONUS=1

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

test: $(LIBFT) $(SRC)
	$(CC) $(TFLAGS) $(INCLUDES) $(SRC) -L $(LIBFT_DIR) $(LIBFT) -o $(NAME)

.PHONY: all clean fclean re test \
get_path.c