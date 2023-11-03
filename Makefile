NAME = pipex
SRCS = main.c \
	pipex.c \
	trans_args.c \
	ft_dup_fds.c \
	ft_close_free.c \
	error_handlers.c \
	arg_check_cmds.c \
	arg_check_files.c
SRC_DIR = ./src/
SRC := $(addprefix $(SRC_DIR), $(SRCS))
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

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

test: $(LIBFT) $(SRC)
	$(CC) $(TFLAGS) $(INCLUDES) $(SRC) -L $(LIBFT_DIR) $(LIBFT) -o $(NAME)

.PHONY: all clean fclean re test \
get_path.c