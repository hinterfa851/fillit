.PHONY: all clean fclean re

.SILENT:

NAME = libft.a
SRC_FILES := $(wildcard *.c)
H_FILES := $(wildcard *.h)
INCLUDES = ./
O_FILES = $(SRC_FILES:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(O_FILES)
	ar -rv $(NAME) $(O_FILES)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o
	/bin/rm -f *.gch
	/bin/rm -f *.out

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
