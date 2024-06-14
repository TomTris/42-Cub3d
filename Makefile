NAME		= cub3d
NAME_DOOR	= cub3d_door
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code
CC = gcc

FT_LIBS =	MLX42/build/libmlx42.a

CFILES	=	main.c\
			strings_utils/len.c\
			displaying/freeing.c\
			displaying/display.c\
			displaying/move_player.c\
			displaying/doors.c\
			displaying/adding_numbers.c\
			displaying/draw_mini_map.c\
			displaying/actual_moving.c\
			displaying/weapon.c\
			rays/ray.c\
			rays/get_cords.c\
			rays/draw_line.c\
			rays/transform_cord_minimap.c\
			rays/horizonatal.c\
			rays/vertical.c\
			To/get_pixel.c



OBJS = $(CFILES:.c=.o)

all:  $(NAME)

$(NAME_DOOR) : $(FT_LIBS) $(OBJS) 
	make -C parsing_bonus
	$(CC)  $(CFLAGS) $(OBJS) parsing_bonus/parsing.a parsing_bonus/libft/libft.a $(FT_LIBS) -o $(NAME_DOOR) -ldl -lglfw -lm -g
	@echo "\033[34m'$(NAME_DOOR)'\033[0m is ready to execute!"
	
$(NAME): $(FT_LIBS) $(OBJS) 
	make -C parsing
	$(CC)  $(CFLAGS) $(OBJS) parsing/parsing.a parsing/libft/libft.a $(FT_LIBS) -o $(NAME) -ldl -lglfw -lm -g
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

bonus: $(NAME_DOOR)

.PHONY: all clean fclean re bonus