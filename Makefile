CC = cc
CFLAGS = -Wall -Werror -Wextra -I./includes/
RM = rm -f
NAME = libftprintf.a

SRCS = srcs/ft_printf.c srcs/putnbr.c srcs/putstr.c

BONUS_SRCS = srcs/ft_printf_bonus.c srcs/parse_bonus.c srcs/dispatch_bonus.c \
	srcs/numeric_bonus.c srcs/output_bonus.c srcs/handlers_bonus.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

bonus: $(BONUS_OBJS)
	$(MAKE) -C ./libft
	cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(BONUS_OBJS)

clean:
	$(MAKE) -C ./libft clean
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
