NAME = push_swap
B_NAME = checker

SRC = constack_b.c helper_f.c push_swap.c create_s.c sorting_r.c constack_a.c scan.c tools.c help_check.c
BONUS = bonus/checker.c bonus/get_next_line.c bonus/get_next_line_utils.c 

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

MANDATORY_OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)
SHARED_OBJ = $(filter-out push_swap.o, $(MANDATORY_OBJ))

all: $(NAME)

$(NAME): $(MANDATORY_OBJ)
	$(CC) $(CFLAGS) $(MANDATORY_OBJ) -o $(NAME)

bonus: $(SHARED_OBJ) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(SHARED_OBJ) $(BONUS_OBJ) -o $(B_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(B_NAME)

re: fclean all
