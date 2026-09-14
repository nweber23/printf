CC = cc
CFLAGS = -Wall -Wextra -Werror -Wno-format -I../includes
NAME = test_bonus

all: $(NAME)

$(NAME): test_bonus.c ../libftprintf.a
	$(CC) $(CFLAGS) test_bonus.c ../libftprintf.a -o $(NAME)

run: all
	./$(NAME)

clean:
	rm -f $(NAME)

.PHONY: all run clean
