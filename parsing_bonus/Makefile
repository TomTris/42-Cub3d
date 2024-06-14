CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = parsing.a

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
	@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir obj

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
