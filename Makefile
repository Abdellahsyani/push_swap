NAME = push_swap

SRC = constack_b.c helper_f.c push_swap.c create_s.c sorting_r.c constack_a.c find_pivot.c Quicksort.c

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
