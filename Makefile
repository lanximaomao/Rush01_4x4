NAME = rush-01
FLAGS = -Wall -Wextra -Werror
SRCS = main.c solver_lliu.c validation.c utils.c
OBJ = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ) $(FLAGS)

$(OBJ): $(SRCS)
	cc -c  $(SRCS) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
