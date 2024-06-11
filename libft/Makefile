CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRC = 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c\
		ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strcpy.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c\
		\
		ft_split.c\
		\
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
		\
		ft_isempty.c ft_strcmp.c ft_trim_white_space.c ft_strdup_middle_del.c\
		ft_isalnum_.c ft_is_valid_word.c ft_empty_cnt.c ft_cnt_valid_word.c ft_strnjoin.c ft_sadd.c\
		\
		get_next_line.c\
		\
		ft_printf.c ft_putc.c ft_putdi.c ft_putp.c ft_puts.c ft_putu.c ft_putx.c ft_putxx.c ft_putx.c\
		ft_printf_fd.c ft_putc_fd.c ft_putdi_fd.c ft_putp_fd.c ft_puts_fd.c ft_putu_fd.c ft_putx_fd.c\
		ft_putxx_fd.c ft_putx_fd.c
OBJS = $(SRC:.c=.o)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f  $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
