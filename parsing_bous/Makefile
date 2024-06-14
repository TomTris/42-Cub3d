CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = parsing.a
LIBFT_DIR = libft
LIBFT_A = libft/libft.a

OBJ_DIR = obj
SRC		= 	parsing.c\
			before_map1.c\
			before_map2.c\
			ft_file_create.c\
			map_gen.c\
			map_gen2.c\
			map_cut.c\
			t_po.c\
			other.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	cc -o $(NAME) $(OBJS) libft/libft.a

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir obj

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
