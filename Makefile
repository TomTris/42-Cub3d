NAME	= cub3d
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code
CC = gcc

FT_LIBS =	MLX42/build/libmlx42.a

CFILES	=	main.c \
displaying/display.c displaying/move_player.c displaying/test.c displaying/adding_numbers.c displaying/draw_mini_map.c displaying/actual_moving.c \
rays/ray.c rays/get_cords.c rays/draw_line.c rays/transform_cord_minimap.c


OBJS = $(CFILES:.c=.o)

all:  $(NAME)
	
$(NAME): $(FT_LIBS) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(FT_LIBS) -o $(NAME) -ldl -lglfw -lm -g
	@echo "\033[34m'$(NAME)'\033[0m is ready to execute!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# $(FT_LIBS): 
# 	git clone https://github.com/codam-coding-college/MLX42.git
# 	cd MLX42 && cmake -B build && cmake --build build -j4

clean:
	@rm -rf $(OBJS)
# @rm -rf MLX42

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re