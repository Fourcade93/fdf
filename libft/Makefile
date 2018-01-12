PART_ONE := ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c \
ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_strnstr.c ft_strncmp.c \
ft_strcmp.c ft_strstr.c ft_strrchr.c ft_strchr.c ft_strlcat.c \
ft_strncat.c ft_strcat.c ft_strncpy.c ft_strcpy.c ft_strdup.c \
ft_strlen.c ft_memcmp.c ft_memchr.c ft_memmove.c ft_memccpy.c \
ft_memcpy.c ft_atoi.c ft_bzero.c ft_memset.c
PART_ONE := $(addprefix part_one/, $(PART_ONE))

PART_TWO := ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c \
ft_putchar_fd.c ft_putnbr.c ft_putendl.c ft_strsplit.c ft_strtrim.c \
ft_strjoin.c ft_strsub.c ft_strmapi.c ft_strmap.c ft_strnequ.c \
ft_strequ.c ft_striteri.c ft_striter.c ft_strclr.c ft_strdel.c \
ft_strnew.c ft_memdel.c ft_memalloc.c ft_itoa.c ft_putstr.c ft_putchar.c
PART_TWO := $(addprefix part_two/, $(PART_TWO))

OTHER := ft_tree_pre.c ft_tree_in.c ft_tree_post.c ft_tree_add_elem.c \
ft_new_tree_elem.c ft_list_pushback.c ft_lstmap.c ft_lstiter.c \
ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstnew.c get_next_line.c \
ft_swap.c ft_del_content.c ft_list_del_back.c ft_lstlen.c \
ft_dlst_pushback.c ft_dlstadd.c ft_dlstdel.c ft_dlstnew.c ft_dlstlen.c \
ft_dlst_toend.c ft_dlstdel_back.c ft_dlstdelone.c
OTHER := $(addprefix other/, $(OTHER))

FT_PRINTF := get_spec.c helpers.c itoa_base.c outputs.c printf_helpers.c \
put_calls.c put_long_calls.c put_long_long_calls.c put_short_calls.c \
put_to_char_calls.c put_to_max_calls.c put_unicode.c put_unicode_helps.c \
put_z_calls.c ft_printf.c
FT_PRINTF := $(addprefix ft_printf/, $(FT_PRINTF))

SRC := $(PART_ONE) $(PART_TWO) $(OTHER) $(FT_PRINTF)
OBJ = $(SRC:.c=.o)
INC_DIR = includes/
NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
CREATE_LIB = ar rc

all: $(SRC) $(NAME)

$(NAME): $(OBJ)
	@$(CREATE_LIB) $@ $^
	@echo "Create libft.a"

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $< -I$(INC_DIR)
clean:
	@/bin/rm -f $(OBJ)
	@echo "Delete object-files"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Delete libft.a"

re: fclean all
