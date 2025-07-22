NAME := fractol
SRC := fractol.c fractol_utils.c maths.c color.c hooks.c
OBJ := $(SRC:.c=.o)

MLX_DIR := MLX42
MLX_INC := $(MLX_DIR)/include/MLX42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror -I$(MLX_INC)
LDFLAGS = -ldl -lglfw -pthread -lm

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
$(MLX_LIB):
	cmake -B $(MLX_DIR)/build $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)/build

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(MLX_DIR)/build clean

re: fclean all
