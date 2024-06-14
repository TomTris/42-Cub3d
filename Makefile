NAME			= cub3d
NAME_BONUS		= cub3d_bonus
CFLAGS			= -Wextra -Wall -Werror -Wunreachable-code
CC 				= cc

PARSING_DIR = parsing
PARSING_BONUS_DIR = parsing_bonus

PARSING = parsing/parsing.a
PARSING_BONUS = parsing_bonus/parsing.a
LIBFT_DIR = libft
FT_LIBS =	MLX42/build/libmlx42.a
LIBFT	= libft/libft.a

SRC	=		cub3d.c\
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
			render/get_pixel.c


OBJS = $(SRC:.c=.o)
all:  $(NAME)

$(NAME_BONUS) : $(FT_LIBS) $(OBJS) $(PARSING_BONUS) $(LIBFT)
	$(CC)  $(CFLAGS) $(OBJS) $(PARSING_BONUS) $(LIBFT) $(FT_LIBS) -o $(NAME_BONUS) -ldl -lglfw -lm -g
	@echo "\033[34m'$(NAME_BONUS)'\033[0m is ready to execute!"
	
$(NAME): $(FT_LIBS) $(OBJS) $(PARSING) $(LIBFT)
	$(CC)  $(CFLAGS) $(OBJS) $(PARSING) $(LIBFT) $(FT_LIBS) -o $(NAME) -ldl -lglfw -lm -g
	@echo "\033[34m'$(NAME)'\033[0m is ready to execute!"

$(PARSING):
	@make -C parsing
$(PARSING_BONUS):
	@make -C parsing_bonus
$(LIBFT):
	@make -C libft

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
$(FT_LIBS):
	@git clone https://github.com/codam-coding-college/MLX42.git
	@cd MLX42 && cmake -B build && cmake --build build -j4


clean:
	@rm -rf $(OBJS)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PARSING_DIR)
	@make fclean -C $(PARSING_BONUS_DIR)
	@rm -rf MLX42

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PARSING_DIR)
	@make fclean -C $(PARSING_BONUS_DIR)

re: fclean all

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re bonus
