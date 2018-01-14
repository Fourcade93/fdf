SRC := main.c error_fnc.c put_pixels.c valid_input.c events.c map_mod.c \
wind_mod.c
SRC := $(addprefix src/, $(SRC))
OBJ := $(SRC:.c=.o)
INC_DIR = includes/
LIB_DIR = libft/
LIB_INC_DIR = $(LIB_DIR)$(INC_DIR)
CC = gcc
FLAGS = -Wall -Werror -Wextra
INC_LIB = -L$(LIB_DIR) -lft
NAME = fdf

all: create_libft $(SRC) $(NAME)

create_libft:
	@make -C $(LIB_DIR)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $@ $^ -lmlx -framework OpenGL -framework  AppKit $(INC_LIB)
	@echo "Create $(NAME)"

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $< -I$(LIB_INC_DIR) -I$(INC_DIR)

clean:
	@/bin/rm -f $(OBJ)
	@make clean -C $(LIB_DIR)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_DIR)

re: fclean all