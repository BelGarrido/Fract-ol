#Nombre del ejecutable
NAME = fractol

#Archivos fuente
SRC = fractol.c fractol_utils.c maths.c color.c
OBJ = $(SRC:.c=.o)

#MLX42 local
MLX_DIR = MLX42
MLX_INC = $(MLX_DIR)/include/MLX42
MLX_LIB = $(MLX_DIR)/build

#Compilación y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(MLX_INC)
LDFLAGS = -L$(MLX_LIB) -lmlx42 -ldl -lglfw -pthread -lm

# Compilar cada .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
# Compilar y enlazar
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

# Limpiar archivos compilados
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


#gcc main.c MLX42/build/libmlx42.a -IMLX42/include -ldl -lglfw -pthread -lm

#Busca los headers en MLX42/include además de los directorios estándar
#	I./MLX42/include
#Busca librerías compiladas en esta carpeta
#	-L./MLX42/build
#Que archivo enlazar: busca un archivo llamado libMLX42.a (o .so) en los directorios especificados con -L
#	-lMLX42
