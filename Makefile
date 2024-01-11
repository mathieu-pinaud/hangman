CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = hangman
SRC = main.c game.c fileToList.c split.c list.c writer.c
OBJ = $(SRC:.c=.o)
LIBS = -lncurses

all: $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)

.PHONY: all clean fclean re